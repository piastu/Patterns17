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
    /// Interaction logic for AddsStation.xaml
    /// </summary>
    public partial class AddsStation : Window
    {
        public AddsStation()
        {
            InitializeComponent();
        }

        public ModelRailRoad momo;
        public MainWindow fath;
        bool fl = false;
        int qwert;
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            int q = momo.getGetArrowsStr();
            for (int i = 0; i < q; i++)
            {
                ComboboxArrowFirst.Items.Add(i);
            }

            ComboboxArrowFirst.Items.Add("номер точки");
            ComboboxArrowFirst.SelectedIndex = q;
            qwert = q;
            fl = true;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            int q;
            if (ComboboxArrowFirst.SelectedIndex == qwert)
            {
                MessageBox.Show("Точка", "Ошибка при вводе Точки", MessageBoxButton.OK, MessageBoxImage.Error);
            }else
            if (!int.TryParse(counts.Text, out q))
            {
                MessageBox.Show("Число", "Ошибка при вводе Числа", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
                momo.addStation(names.Text, ComboboxArrowFirst.SelectedIndex, q);
                Close();
            }
            
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            fath.refresh();
        }

        private void ComboboxArrowFirst_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (fl)
            {
                fath.refresh();
                if (ComboboxArrowFirst.SelectedIndex != qwert)
                {
                    fath.SelectArrow(ComboboxArrowFirst.SelectedIndex);
                }
            }
        }
    }
}
