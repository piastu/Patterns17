import UIKit

class PageViewController: UIPageViewController {
    
    var pageImages = ["0", "1", "2", "3", "4", "5", "6"]

    override func viewDidLoad() {
        super.viewDidLoad()
        dataSource = self
        
        if let startWalkthroughVC = viewController(atIndex: 0) {
            setViewControllers([startWalkthroughVC], direction: .forward, animated: true, completion: nil)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func nextPage(withIndex index: Int) {
        
    }
    
    func viewController(atIndex index: Int) -> WelcomeViewController? {
        
        if index == NSNotFound || index < 0 || index >= pageImages.count {
            return nil
        }
        if let welcomeVC = storyboard?.instantiateViewController(withIdentifier: "WelcomeViewController") as? WelcomeViewController {
            welcomeVC.imageName = pageImages[index]
            welcomeVC.index = index
            return welcomeVC
        }
        
        return nil
    }

}

extension PageViewController : UIPageViewControllerDataSource {
    
    func pageViewController(_ pageViewController: UIPageViewController, viewControllerBefore viewController: UIViewController) -> UIViewController? {
        //
        var index = (viewController as! WelcomeViewController).index
        index -= 1
        return self.viewController(atIndex: index)
    }
    
    func pageViewController(_ pageViewController: UIPageViewController, viewControllerAfter viewController: UIViewController) -> UIViewController? {
        //
        var index = (viewController as! WelcomeViewController).index
        index += 1
        return self.viewController(atIndex: index)
    }
}
