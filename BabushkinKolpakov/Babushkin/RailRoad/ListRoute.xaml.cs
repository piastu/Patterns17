using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace RailRoad
{
    /// <summary>
    /// Interaction logic for ListRoute.xaml
    /// </summary>
    public partial class ListRoute : Window
    {
        public ListRoute()
        {
            InitializeComponent();
        }

        public ModelRailRoad momo;
        public MainWindow fath;
        bool fl = false;
        int qwert;
        List<string> q;
        List<Route> zz;
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            q = momo.getGetRouteStr();
            zz = momo.LRoute;
        }
        private void lis_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            if (fl)
            {
                fath.refreshNoChil();
                fath.SelectRoute(zz[listsss.SelectedIndex]);
            }
        }

        public void refresh()
        {
            fl = false;
            listsss.Items.Clear();
            q = momo.getGetRouteStr();
            for(int i = 0 ; i< q.Count; i++)
            {
                listsss.Items.Add(q[i]);
            }
            fl = true;
        }


        private void Window_Closed(object sender, EventArgs e)
        {
            fath.Close();
        }

    }
}
