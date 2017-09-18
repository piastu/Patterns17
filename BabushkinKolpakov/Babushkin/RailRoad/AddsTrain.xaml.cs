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
    /// Interaction logic for AddsTrain.xaml
    /// </summary>
    public partial class AddsTrain : Window
    {
        public AddsTrain()
        {
            InitializeComponent();
        }

        public ModelRailRoad momo;
        public MainWindow fath;
        bool fl = false;

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            
            fl = true;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            double q;
            if(!double.TryParse(sp.Text, out q))
            {
                MessageBox.Show("Скорость", "Ошибка при вводе Скорости", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
             
                momo.AddTrain(na.Text, q);
                Close();
            }
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            fath.refresh();
        }

    }
}
