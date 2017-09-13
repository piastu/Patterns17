import UIKit
import MultipeerConnectivity

extension Notification.Name {
    static let didChangeState = NSNotification.Name("MPC_DidChangeStateNotification")
    static let didReceiveData = NSNotification.Name("MPC_DidReceiveDataNotification")
}

class ViewController: UIViewController, MCBrowserViewControllerDelegate {

    @IBOutlet var fields: [TTTImageView]!
    
    var appDelegate: AppDelegate!
    var currentPlayer: String!
    var handler: MPCHandler!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        appDelegate = UIApplication.shared.delegate as! AppDelegate
        handler = appDelegate.mpcHandler
        handler.setupPeerWith(displayName: UIDevice.current.name)
        handler.setupSession()
        handler.advertiseSelf(advertise: true)
        
        let nc = NotificationCenter.default
        nc.addObserver(forName: .didChangeState, object: nil, queue: nil, using: peerChangedStateWithNotification(_:))
        nc.addObserver(forName: .didReceiveData, object: nil, queue: nil, using: handleReceivedDataWithNotification(_:))
        
        setupField()
        displayWelcome()
    }
    
    func peerChangedStateWithNotification(_ notification:Notification) {
        let userInfo = NSDictionary(dictionary: notification.userInfo!)
        let state = userInfo.object(forKey: "state") as! MCSessionState
        if state == MCSessionState.connected {
            navigationItem.title = "Connected"
        } else if state == MCSessionState.notConnected {
            navigationItem.title = "Not connected"
        }
    }
    
    func handleReceivedDataWithNotification(_ notification:Notification) {
        let userInfo = notification.userInfo! as Dictionary
        let receivedData: Data = userInfo["data"] as! Data
        let message = try! JSONSerialization.jsonObject(with: receivedData, options: .allowFragments) as! NSDictionary
        let senderPeerId: MCPeerID = userInfo["peerID"] as! MCPeerID
        let senderDisplayName = senderPeerId.displayName
        
        if (message.object(forKey: "string") as AnyObject).isEqual("New Game") {
            let alert = UIAlertController(
                title: "TicTacToe", message: "\(senderDisplayName) has started a new game", preferredStyle: .alert)
            
            alert.addAction(UIAlertAction(
                title: "OK", style: .default, handler: nil))
            present(alert, animated: true, completion: nil)
            resetField()
        }
        else{
            
            let field:Int? = (message.object(forKey: "field") as AnyObject).integerValue
            
            let player:String? = message.object(forKey: "player") as? String
            
            if field != nil && player != nil{
                fields[field!].player = player
                fields[field!].setPlayerSign(player!)
                
                if player == "x"{
                    currentPlayer = "o"
                }else{
                    currentPlayer = "x"
                }
                checkResults()
            }
        }
    }

    @IBAction func newGame(_ sender: Any) {
        resetField()
        
        let messageDict = ["string": "New Game"]
        if let messageData = try? JSONSerialization.data(withJSONObject: messageDict, options: .prettyPrinted){
            if (try? handler.session.send(messageData, toPeers: handler.session.connectedPeers, with: .reliable)) != nil{
                print("New Game button pressed")
            }
        }
    }
    
    func checkResults(){
        var winner: String? = nil
        var alert: UIAlertController!
        let x: String! = "x"
        let o: String! = "o"
        
        if fields[0].player == x && fields[1].player == x && fields[2].player == x{
            winner = x
        }else if fields[0].player == o && fields[1].player == o && fields[2].player == o{
            winner = o
        }else if fields[3].player == x && fields[4].player == x && fields[5].player == x{
            winner = x
        }else if fields[3].player == o && fields[4].player == o && fields[5].player == o{
            winner = o
        }else if fields[6].player == x && fields[7].player == x && fields[8].player == x{
            winner = x
        }else if fields[6].player == o && fields[7].player == o && fields[8].player == o{
            winner = o
        }else if fields[0].player == x && fields[3].player == x && fields[6].player == x{
            winner = x
        }else if fields[0].player == o && fields[3].player == o && fields[6].player == o{
            winner = o
        }else if fields[1].player == x && fields[4].player == x && fields[7].player == x{
            winner = x
        }else if fields[1].player == o && fields[4].player == o && fields[7].player == o{
            winner = o
        }else if fields[2].player == x && fields[5].player == x && fields[8].player == x{
            winner = x
        }else if fields[2].player == o && fields[5].player == o && fields[8].player == o{
            winner = o
        }else if fields[0].player == x && fields[4].player == x && fields[8].player == x{
            winner = x
        }else if fields[0].player == o && fields[4].player == o && fields[8].player == o{
            winner = o
        }else if fields[2].player == x && fields[4].player == x && fields[6].player == x{
            winner = x
        }else if fields[2].player == o && fields[4].player == o && fields[6].player == o{
            winner = o
        }
        if (winner != nil) {
            alert = UIAlertController(
                title: "Tic Tac Toe", message: "The winner is \(winner!.uppercased())", preferredStyle: .alert)
            alert.addAction(UIAlertAction(
                title: "OK", style: .default, handler: {(alert:UIAlertAction!) -> Void in self.resetField()}))
            present(alert, animated: true, completion: nil)
        }
    }
    
    @IBAction func connectWithPlayer(_ sender: Any) {
        if handler.session != nil {
            handler.setupBrowser()
            handler.browser.delegate = self
            present(handler.browser, animated: true, completion: nil)
        }
    }
    
    func fieldTapped(_ gestureRecognizer: UITapGestureRecognizer){
        let tappedField = gestureRecognizer.view as! TTTImageView
        if currentPlayer != nil {
            tappedField.setPlayerSign(currentPlayer)
            
            let messageDict = ["field": tappedField.tag, "player": currentPlayer] as [String : Any]
            if let messageData = try? JSONSerialization.data(withJSONObject: messageDict, options: .prettyPrinted) {
                if (try? handler.session.send(messageData, toPeers: handler.session.connectedPeers, with: .reliable)) != nil {
                }
            }
            checkResults()
        }
    }
    
    func setupField() {
        for index in 0 ... fields.count - 1 {
            let gestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(fieldTapped(_:)))
            gestureRecognizer.numberOfTapsRequired = 1
            fields[index].addGestureRecognizer(gestureRecognizer)
        }
    }
    
    func resetField(){
        for index in 0 ... fields.count - 1{
            fields[index].image = nil
            fields[index].activated = false
            fields[index].player = ""
        }
        currentPlayer = "x"
    }
    
    func browserViewControllerDidFinish(_ browserViewController: MCBrowserViewController) {
        handler.browser.dismiss(animated: true, completion: nil)
    }
    func browserViewControllerWasCancelled(_ browserViewController: MCBrowserViewController) {
        handler.browser.dismiss(animated: true, completion: nil)
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func displayWelcome() {
        let defaults = UserDefaults.standard
        // Delete next line for going further than welcome
        defaults.set(true, forKey: "isFirstOpen")
        if let isFirstOpen = defaults.object(forKey: "isFirstOpen") as! Bool? {
            if isFirstOpen {
                if let pageVC = storyboard?.instantiateViewController(withIdentifier: "PageViewController") {
                    present(pageVC, animated: true, completion: nil)
                }
            }
        }
        else {
            defaults.set(true, forKey: "isFirstOpen")
        }
    }
}

