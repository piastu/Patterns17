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
    /// Interaction logic for AddsRoad.xaml
    /// </summary>
    public partial class AddsRoad : Window
    {
        public AddsRoad()
        {
            InitializeComponent();
        }

        public ModelRailRoad momo;
        public MainWindow fath;
        bool fl = false;
        int qwert;

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            double asd;
            if (ComboboxArrowFirst.SelectedIndex == qwert || ComboboxArrowFirst.SelectedIndex == ComboboxArrowSecond.SelectedIndex)
            {
                MessageBox.Show("Точка", "Ошибка при вводе Точки", MessageBoxButton.OK, MessageBoxImage.Error);
            }else
            if(!double.TryParse(len.Text, out asd))
            {
                 MessageBox.Show("Длина", "Ошибка при вводе Длины", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
                momo.addRoad(ComboboxArrowFirst.SelectedIndex, ComboboxArrowSecond.SelectedIndex, asd, (bool)CheckSingeRoad.IsChecked);
                Close();
            }
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            int q = momo.getGetArrowsStr();
            for (int i = 0; i < q; i++)
            {
                ComboboxArrowFirst.Items.Add(i);
                ComboboxArrowSecond.Items.Add(i);
            }
            qwert = q;
            ComboboxArrowFirst.Items.Add("номер точки");
            ComboboxArrowFirst.SelectedIndex = q;
            ComboboxArrowSecond.Items.Add("номер точки");
            ComboboxArrowSecond.SelectedIndex = q;
            fl = true;
        }

        private void ComboboxArrowFirst_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (fl)
            {
                fath.refresh();
                if (ComboboxArrowFirst.SelectedIndex != qwert && ComboboxArrowFirst.SelectedIndex != ComboboxArrowSecond.SelectedIndex)
                {
                    fath.SelectArrow(ComboboxArrowFirst.SelectedIndex);
                }
                if (ComboboxArrowSecond.SelectedIndex != qwert && ComboboxArrowFirst.SelectedIndex != ComboboxArrowSecond.SelectedIndex)
                {
                    fath.SelectArrow(ComboboxArrowSecond.SelectedIndex);
                }
            }
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            fath.refresh();
        }

        private void ComboboxArrowSecond_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (fl)
            {
                fath.refresh();
                if (ComboboxArrowFirst.SelectedIndex != qwert && ComboboxArrowFirst.SelectedIndex != ComboboxArrowSecond.SelectedIndex)
                {
                    fath.SelectArrow(ComboboxArrowFirst.SelectedIndex);
                }
                if (ComboboxArrowSecond.SelectedIndex != qwert && ComboboxArrowFirst.SelectedIndex != ComboboxArrowSecond.SelectedIndex)
                {
                    fath.SelectArrow(ComboboxArrowSecond.SelectedIndex);
                }
            }
        }
    }
}
