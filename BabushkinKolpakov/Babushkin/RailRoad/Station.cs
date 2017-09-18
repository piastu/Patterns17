using System;
using System.Drawing;
using System.Collections.Generic;
using System.Windows;

namespace RailRoad
{
    ///
    /// <summary> * Created by IDIB on 27.09.2015.
    /// *  класс станции </summary>
    /// 
    [Serializable()]
	public class Station: ObjectRoad
	{
        public string Name; // имя станции
        public int CountPlatforms; // количество платформ
        public List<Platform> Platforms; // платформы

        public Station():base()
        {

        }

        public Station(Int64 _id, Point _coord)
            : base(_id,_coord)
        {

        }

		public bool Pick(DateTime Begin, DateTime End, Route Trek)
		{
			bool fl = false;
			for (int i = 0; i < CountPlatforms && !fl; i++)
				if (Platforms[i].Pick(Begin, End, Trek))
				{
					fl = true;
				}
			return fl;
		}

        public Station(Int64 _id,  Arrow r, int n)
            :base(_id,r.Coord)
        {
            Platforms = new List<Platform>();
            CountPlatforms = n;
            for (int i = 0; i < n; i++)
                Platforms.Add(new Platform(_id, r));
        }

		public Arrow[] GetArrow()
		{
			Arrow[] a = new Arrow[CountPlatforms];
			for (int i = 0; i < Platforms.Count; i++)
			{
				a[i] = Platforms[i].getArrow();
			}
			return a;
		}


	}

}