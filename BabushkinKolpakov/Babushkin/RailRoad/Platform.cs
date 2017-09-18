using System;
using System.Collections.Generic;
using System.Windows;

namespace RailRoad
{
    ///
    /// <summary> * Created by IDIB on 10.10.2015. </summary>
    /// 
    [Serializable()]
	public class Platform: ObjectRoad
	{
        public int numberPlanform; // номер платформы
        public int count; // количаство элементов в листах
        public List<DateTime> BeginLock; // начала заблокированиого периода
        public List<DateTime> EndLock; // конец переиода
        public List<Route> RouteLock; // маршрут
        public Arrow BeginArrow; // точка на карте

        public Platform()
            : base()
        {

        }

        public Platform(Int64 _id, Point _coord)
            : base(_id,_coord)
        {

        }
        public Platform(Int64 _id, Arrow _coord)
            : base(_id, _coord.Coord)
        {
            BeginArrow = _coord;
        }

		public bool TryPick(DateTime Start, DateTime End, Arrow st)
		{
			bool fl = true;
			for (int i = 0; i < count; i++)
			{
				if(BeginLock[i] < Start && EndLock[i] > End)
				{
					fl = false;
				}
			}
			return fl;
		}

		public bool Pick(DateTime Start, DateTime End, Route RouteT)
		{
			bool fl = true;
			for (int i = 0; i < count; i++)
			{
                if (BeginLock[i] < Start && EndLock[i] > End)
				{
					fl = false;
				}
			}
			if(fl)
			{
				BeginLock.Add(Start);
				EndLock.Add(End);
				RouteLock.Add(RouteT);
				count++;
			}
			return fl;
		}

		public Arrow getArrow()
		{
			return BeginArrow;
		}

		public void UpDate(DateTime now)
		{
			for (int i = 0; i < count; i++)
			{
				if(EndLock[i] < now)
				{
					BeginLock.RemoveAt(i);
					EndLock.RemoveAt(i);
					RouteLock.RemoveAt(i);
					i--;
					count--;
				}
			}
		}
	}

}