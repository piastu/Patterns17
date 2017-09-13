import UIKit

class WelcomeViewController: UIViewController {

    @IBOutlet weak var imageView: UIImageView!
    @IBOutlet weak var pageControl: UIPageControl!
    @IBOutlet weak var skipButton: UIButton!
    
    var index = 0
    var imageName = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        imageView.image = UIImage(named: imageName)
        pageControl.numberOfPages = 7
        pageControl.pageIndicatorTintColor = #colorLiteral(red: 0.6657042861, green: 0.8280222483, blue: 1, alpha: 1)
        pageControl.currentPageIndicatorTintColor = #colorLiteral(red: 0.2392156869, green: 0.6745098233, blue: 0.9686274529, alpha: 1)
        pageControl.currentPage = index
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    @IBAction func skipClicked(_ sender: Any) {
        let userDefaults = UserDefaults.standard
        userDefaults.set(false, forKey: "isFirstOpen")
        dismiss(animated: true, completion: nil)
    }
    
}
