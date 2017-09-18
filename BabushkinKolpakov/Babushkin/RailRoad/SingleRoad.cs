using System;
using System.Collections.Generic;
using System.Windows;

namespace RailRoad
{
    ///
    /// <summary> * Created by IDIB on 11.10.2015. </summary>
    /// 
    [Serializable()]
	public class SingleRoad : Road
	{
        public int count; // количество элементов в листах
        public List<DateTime> BeginLock; // начало бликирови
        public List<DateTime> EndLock; // конец блокировки
        public List<bool> VectorLock; // направление блокировки

        public SingleRoad()
            : base()
		{
		}

        public SingleRoad(int _id, Point _coord,  Arrow arrowFirst, Arrow arrowSecond, double len)
            : base(_id, _coord, arrowFirst, arrowSecond, len)
		{
		}

		public bool TryPick(DateTime Start, DateTime End, Arrow st)
		{
			bool fl = true;
			bool vec;
			if (ArrowFirst == st)
				vec = true;
			else
				vec = false;
			for (int i = 0; i < count && fl; i++)
			{
				if((EndLock[i] >  Start && BeginLock[i+1] <End && (VectorLock[i] != vec)))
				{
					fl = false;
				}
			}
			return fl;
		}

		public bool Pick(DateTime Start, DateTime End, Arrow st)
		{
			bool fl = true;
			bool vec;
			if (ArrowFirst == st)
				vec = true;
			else
				vec = false;
			for (int i = 0; i < count && fl; i++)
			{
				if((EndLock[i] > Start) && BeginLock[i+1] < End && (VectorLock[i] != vec))
				{
					fl = false;
				}
			}
			if(fl)
			{
				BeginLock.Add(Start);
				EndLock.Add(End);
				VectorLock.Add(vec);
				count++;
			}
			return fl;
		}

		public void UpDate(DateTime now)
		{
			for (int i = 0; i < count; i++)
			{
				if(EndLock[i] > now)
				{
                    BeginLock.RemoveAt(i);
					EndLock.RemoveAt(i);
					i--;
					count--;
				}
			}
		}
	}

}