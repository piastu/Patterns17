using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using System.Xml.Serialization;
using Microsoft.Win32;

namespace RailRoad
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        ModelRailRoad mod;
        Point MouseOld;
        private SolidColorBrush colorBrown = new SolidColorBrush(Colors.Brown);
        private SolidColorBrush colorBlack = new SolidColorBrush(Colors.Black);
        private SolidColorBrush colorRed = new SolidColorBrush(Colors.Red);
        ListRoute chil;
        string filma;

        public MainWindow()
        {
            filma = "b.dat";
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            mod = new ModelRailRoad();
            chil = new ListRoute();
            chil.momo = mod;
            chil.fath = this;
            chil.Show();
        }
        
        private void AddArrowWPF(object sender, RoutedEventArgs e)
        {
            mod.addArrow(MouseOld);
            refresh();
        }

        private void AddRoadWPF(object sender, RoutedEventArgs e)
        {
            AddsRoad formss = new AddsRoad();
            formss.momo = mod;
            formss.fath = this;
            formss.Show();
        }

        private void Savemod(object sender, RoutedEventArgs e)
        {
            XmlSerializer formatter = new XmlSerializer(typeof(ModelRailRoad));
            FileStream fs = new FileStream(filma, FileMode.OpenOrCreate);
            formatter.Serialize(fs, mod);
        }

        public void SelectArrow(int i)
        {
            List<Arrow> LArrow = mod.getArrows();
            Ellipse a = new Ellipse();
            a.Width = 10;
            a.Height = 10;
            a.Fill = colorRed;
            a.SetValue(Canvas.LeftProperty, LArrow[i].Coord.X);
            a.SetValue(Canvas.TopProperty, LArrow[i].Coord.Y);
            CanvasRoad.Children.Add(a);
        }

        public void SelectStation(int i)
        {
            List<Station> LStation = mod.getStations();
            Rectangle r = new Rectangle();
            r.Width = 30;
            r.Height = 10;
            r.Fill = colorRed;
            r.SetValue(Canvas.LeftProperty, LStation[i].Coord.X);
            r.SetValue(Canvas.TopProperty, LStation[i].Coord.Y);
            CanvasRoad.Children.Add(r);
        }

        public void SelectRoute(Route z)
        {
            for (int i = 1; i < z.RouteListA.Count; i++)
            {
                Line a = new Line();
                a.Fill = colorBlack;
                a.Stroke = Brushes.Red;
                a.StrokeThickness = 2;
                Arrow w = z.RouteListA[i-1];
                Arrow zz = z.RouteListA[i];
                a.X1 = w.Coord.X;
                a.Y1 = w.Coord.Y;
                a.X2 = zz.Coord.X;
                a.Y2 = zz.Coord.Y;
                CanvasRoad.Children.Add(a);
            }
        }

        public void refreshNoChil()
        {
            CanvasRoad.Children.Clear();
            List<Road> z = mod.getRoads();
            for (int i = 0; i < z.Count; i++)
            {
                Line a = new Line();
                a.Fill = colorBlack;
                a.Stroke = Brushes.Black;
                a.StrokeThickness = 2;
                Arrow[] w = z[i].GetAllArrows();
                a.X1 = w[0].Coord.X;
                a.Y1 = w[0].Coord.Y;
                a.X2 = w[1].Coord.X;
                a.Y2 = w[1].Coord.Y;
                CanvasRoad.Children.Add(a);
            }

            List<Station> LStation = mod.getStations();
            List<Arrow> LArrow = mod.getArrows();
            for (int i = 0; i < LStation.Count; i++)
            {
                Rectangle r = new Rectangle();
                r.Width = 15;
                r.Height = 10;
                r.Fill = colorBrown;
                r.SetValue(Canvas.LeftProperty, LStation[i].Coord.X);
                r.SetValue(Canvas.TopProperty, LStation[i].Coord.Y);
                CanvasRoad.Children.Add(r);
            }

            for (int i = 0; i < LArrow.Count; i++)
            {
                Ellipse a = new Ellipse();
                a.Width = 5;
                a.Height = 5;
                a.Fill = colorBrown;
                a.SetValue(Canvas.LeftProperty, LArrow[i].Coord.X);
                a.SetValue(Canvas.TopProperty, LArrow[i].Coord.Y);
                CanvasRoad.Children.Add(a);
            }
        }

        public void  refresh()
        {
            chil.refresh();
            refreshNoChil();
        }

        private void AddStationWPF(object sender, RoutedEventArgs e)
        {
            AddsStation f = new AddsStation();
            f.momo = mod;
            f.fath = this;
            f.Show();
        }

        private void AddTrainWPF(object sender, RoutedEventArgs e)
        {
            AddsTrain f = new AddsTrain();
            f.momo = mod;
            f.fath = this;
            f.Show();
        }

        private void AddRouteWPF(object sender, RoutedEventArgs e)
        {
            AddsRoute f = new AddsRoute();
            f.momo = mod;
            f.fath = this;
            f.Show();
            refresh();
        }

        private void Window_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            MouseOld = e.GetPosition(this);
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            chil.Close();
        }
    }
}
