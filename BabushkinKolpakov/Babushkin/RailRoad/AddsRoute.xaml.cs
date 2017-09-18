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
    /// Interaction logic for AddsRoute.xaml
    /// </summary>
    public partial class AddsRoute : Window
    {
        public AddsRoute()
        {
            InitializeComponent();
        }

        public ModelRailRoad momo;
        public MainWindow fath;
        bool fl = false;
        int qwert,qw;
        List<Route> lr;
        bool qhgk = false;
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            List<string> q = momo.getGetStationStr();
            for (int i = 0; i < q.Count; i++)
            {
                ComboboxArrowFirst.Items.Add(q[i]);
                ComboboxArrowSecond.Items.Add(q[i]);
            }
            qwert = q.Count;
            ComboboxArrowFirst.Items.Add("Название станции");
            ComboboxArrowFirst.SelectedIndex = q.Count;
            ComboboxArrowSecond.Items.Add("Название станции");
            ComboboxArrowSecond.SelectedIndex = q.Count;
            q = momo.getGetTrainStr();
            for (int i = 0; i < q.Count; i++)
            {
                ComboboxArrowTrid.Items.Add(q[i]);
            }
            ComboboxArrowTrid.Items.Add("Название станции");
            qw = q.Count;
            dad.SelectedDate = DateTime.Now;
            fl = true;
        }

        private void ComboboxArrowFirst_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (fl)
            {
                fath.refresh();
                if (ComboboxArrowFirst.SelectedIndex != qwert && ComboboxArrowFirst.SelectedIndex != ComboboxArrowSecond.SelectedIndex)
                {
                    fath.SelectStation(ComboboxArrowFirst.SelectedIndex);
                }
                if (ComboboxArrowSecond.SelectedIndex != qwert && ComboboxArrowFirst.SelectedIndex != ComboboxArrowSecond.SelectedIndex)
                {
                    fath.SelectStation(ComboboxArrowSecond.SelectedIndex);
                }
            }
        }

        private void ComboboxArrowSecond_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (fl)
            {
                fath.refresh();
                if (ComboboxArrowFirst.SelectedIndex != qwert && ComboboxArrowFirst.SelectedIndex != ComboboxArrowSecond.SelectedIndex)
                {
                    fath.SelectStation(ComboboxArrowFirst.SelectedIndex);
                }
                if (ComboboxArrowSecond.SelectedIndex != qwert && ComboboxArrowFirst.SelectedIndex != ComboboxArrowSecond.SelectedIndex)
                {
                    fath.SelectStation(ComboboxArrowSecond.SelectedIndex);
                }
            }
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            fath.refresh();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            fl = false;
            double asd;
            DateTime lkj = (DateTime)dad.SelectedDate;
            string[] str = timess.Text.Split(':');
            int h = 0, m = 0, nn;
            bool t= true;
            if(str.Length != 2)
            {
                t = false;
            }
            else
            {
                t = (int.TryParse(str[0], out h)&&(int.TryParse(str[1],out m)));  
            }
            if (ComboboxArrowFirst.SelectedIndex == qwert || ComboboxArrowFirst.SelectedIndex == ComboboxArrowSecond.SelectedIndex)
            {
                MessageBox.Show("Станция", "Ошибка при вводе Станции", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            if(!t)
            {
                MessageBox.Show("Дата время", "Ошибка при вводе Даты или времени", MessageBoxButton.OK, MessageBoxImage.Error);
            }else if (!int.TryParse(nums.Text,out nn)&& nn >=0){
                MessageBox.Show("Количество", "Ошибка при вводе Количество", MessageBoxButton.OK, MessageBoxImage.Error);
            }else if (ComboboxArrowTrid.SelectedIndex == qwert)
            {
                MessageBox.Show("Поезд", "Ошибка при вводе Поезда", MessageBoxButton.OK, MessageBoxImage.Error);
            }else{
                lkj = new DateTime(lkj.Year,lkj.Month,lkj.Day,h,m,0);
                lis.Items.Clear();
                 lr = momo.FindRoute(Rname.Text,ComboboxArrowFirst.SelectedIndex,ComboboxArrowSecond.SelectedIndex,nn,lkj,ComboboxArrowTrid.SelectedIndex);
                for (int i = 0 ;i < lr.Count; i++)
                {
                    
                    lis.Items.Add(lr[i].tostr());
                }
                qhgk = true;
            }
            fl = true;
        }

        private void lis_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            if (fl)
            {
                fath.refresh();
                fath.SelectRoute(lr[lis.SelectedIndex]);
            }
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            if (qhgk && lis.SelectedIndex != -1)
            momo.AddRoute(lr[lis.SelectedIndex]);
            fath.refresh();
        }
    }
}
