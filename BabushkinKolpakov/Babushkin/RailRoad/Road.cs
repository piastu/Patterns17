using System;
using System.Windows;

namespace RailRoad
{
    ///
    /// <summary> * Created by IDIB on 10.10.2015. </summary>
    /// 
    [Serializable()]
	public class Road: ObjectRoad
	{
        public double lenght; // длина пути
        public double cruiserSpeed; // курсовая скорость

        public Arrow ArrowFirst; // кооднитата начала
        public Arrow ArrowSecond; // кооднитата начала
        
        public double Lenght
        {
            get
            {
                return lenght;
            }
            set
            {
                lenght = value;
            }
        }

        public double CruiserSpeed
        {
            get
            {
                return cruiserSpeed;
            }
            set
            {
                cruiserSpeed = value;
            }
        }

        public Road():base()
        {

        }

        public Road(Int64 _id, Point _coord,  Arrow arrowFirst, Arrow arrowSecond, double len)
            : base(_id, _coord)
		{
            lenght = len;
			ArrowFirst = arrowFirst;
			ArrowSecond = arrowSecond;
		}

		public Arrow[] GetAllArrows()
		{
			Arrow[] z = new Arrow[2];
			z[0] = ArrowFirst;
			z[1] = ArrowSecond;
			return z;
		}

        public Arrow GetArrow(Arrow a)
        {
            if (ArrowFirst != null && a == ArrowFirst && ArrowSecond != null)
            {
                return ArrowSecond;
            }
            if (ArrowSecond != null && a == ArrowSecond && ArrowFirst != null)
            {
                return ArrowFirst;
            }
            return null;
        }
	}

}