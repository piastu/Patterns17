import UIKit

class TTTImageView: UIImageView {

    var player: String? = nil
    var activated: Bool! = false

    func setImage() {
        image = UIImage(named: player!)
    }
    
    func setPlayerSign(_ playerSign: String) {
        player = playerSign
        if !activated {
            setImage()
            activated = true
        }
    }
}
