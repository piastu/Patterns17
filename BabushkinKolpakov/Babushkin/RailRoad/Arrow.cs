using System;
using System.Windows;

namespace RailRoad
{


///
/// <summarY> * Created bY IDIB on 23.10.2015. </summarY>
    /// 
    [Serializable()]
	public class Arrow :ObjectRoad
	{
        public int UsedFitst; // количество путей в 1 части
        public int UsedSecond; // количество путей в 2 части
        public Road[] First; // пути
        public Road[] Second; // пути
        public bool OnStantio; // если точка есть станция
        public Platform Stat; // сама станция

		public Arrow()
            :base()
		{
			UsedFitst = 0;
			UsedSecond = 0;
			First = new Road[2];
			Second = new Road[2];
		}

		public Arrow(Int64 _id, Point _coords)
            : base(_id,_coords)
		{
			UsedFitst = 0;
			UsedSecond = 0;
			First = new Road[2];
			Second = new Road[2];
		}

        public Arrow(Int64 _id, Point _coords, Road first)
            : base(_id, _coords)
		{
			UsedFitst = 1;
			UsedSecond = 0;
			First = new Road[2];
			First[0] = first;
			Second = new Road[2];
		}

        public Arrow(Int64 _id, Point _coords, Road[] first)
            : base(_id, _coords)
		{
			UsedFitst = 1;
			UsedSecond = 0;
			First = first;
			Second = new Road[2];
		}

        public Arrow(Int64 _id, Point _coords, Road[] second, Road[] first)
            : base(_id, _coords)
		{
			Second = second;
			First = first;
			coords = _coords;
		}

		public bool Add(Road a)
		{
			if(UsedFitst == 0 && UsedSecond == 0)
			{
				First[0] = a;
				UsedFitst++;
				return true;
			}
			Point s = new Point();
			Arrow[] z = a.GetAllArrows();
			if(z.Length == 2 && z[0] == this)
			{
				s.X = coords.X - z[1].coords.X;
				s.Y = coords.Y - z[1].coords.Y;
			}
			if(z.Length == 2 && z[1] == this)
			{
				s.X = coords.X - z[0].coords.X;
				s.Y = coords.Y - z[0].coords.Y;
			}
			for (int i = 0; i < First.Length; i++)
			{
				if(First[i] != null)
				{
					Point q = coords;
                    z = First[i].GetAllArrows();
					if(z.Length == 2 && z[0] == this)
					{
						q.X = coords.X - z[1].coords.X;
						q.X = coords.Y - z[1].coords.Y;
					}
					if(z.Length == 2 && z[1] == this)
					{
						q.X = coords.X - z[0].coords.X;
						q.X = coords.Y - z[0].coords.Y;
					}
					double arc = Math.Acos ((s.X * q.X + s.Y * q.Y)/Math.Sqrt((s.X*s.X + s.Y*s.Y)*(q.X*q.X + q.Y*q.Y)));
					if(UsedFitst < 1 && arc > 0 && arc < 1)
					{
                        First[UsedFitst] = a;
						UsedFitst++;
						return true;
					}
					if(UsedSecond < 1 && arc > -1 && arc < 0)
					{
                        Second[UsedSecond] = a;
                        UsedSecond++;
						return true;
					}
				}
			}
			for (int i = 0; i < Second.Length; i++)
			{
				if(Second[i] != null)
				{
					Point q = coords;
                    z = Second[i].GetAllArrows();
					if(z.Length == 2 && z[0] == this)
					{
						q.X = coords.X - z[1].coords.X;
						q.X = coords.Y - z[1].coords.Y;
					}
					if(z.Length == 2 && z[1] == this)
					{
						q.X = coords.X - z[0].coords.X;
						q.X = coords.Y - z[0].coords.Y;
					}
					double arc = Math.Acos ((s.X * q.X + s.Y * q.Y)/Math.Sqrt((s.X*s.X + s.Y*s.Y)*(q.X*q.X + q.Y*q.Y)));
					if(arc > 0 && arc < 1)
					{
						if(UsedSecond < 1)
						{
                            Second[UsedSecond] = a;
                            UsedSecond++;
							return true;
						}
						if(UsedFitst < 1)
						{
                            First[UsedFitst] = a;
							UsedFitst++;
							return true;
						}
					}
				}
			}
			return false;
		}

        public bool TryPick(Road a)
        {
            if (UsedFitst == 0 && UsedSecond == 0)
            {
                UsedFitst++;
                return true;
            }
            Point s = new Point();
            Arrow[] z = a.GetAllArrows();
            if (z.Length == 2 && z[0] == this)
            {
                s.X = coords.X - z[1].coords.X;
                s.Y = coords.Y - z[1].coords.Y;
            }
            if (z.Length == 2 && z[1] == this)
            {
                s.X = coords.X - z[0].coords.X;
                s.Y = coords.Y - z[0].coords.Y;
            }
            for (int i = 0; i < First.Length; i++)
            {
                if (First[i] != null)
                {
                    Point q = coords;
                    z = First[i].GetAllArrows();
                    if (z.Length == 2 && z[0] == this)
                    {
                        q.X = coords.X - z[1].coords.X;
                        q.X = coords.Y - z[1].coords.Y;
                    }
                    if (z.Length == 2 && z[1] == this)
                    {
                        q.X = coords.X - z[0].coords.X;
                        q.X = coords.Y - z[0].coords.Y;
                    }
                    double arc = Math.Acos((s.X * q.X + s.Y * q.Y) / Math.Sqrt((s.X * s.X + s.Y * s.Y) * (q.X * q.X + q.Y * q.Y)));
                    if (UsedFitst < 1 && arc > 0 && arc < 1)
                    {
                        UsedFitst++;
                        return true;
                    }
                    if (UsedSecond < 1 && arc > -1 && arc < 0)
                    {
                        UsedSecond++;
                        return true;
                    }
                }
            }
            for (int i = 0; i < Second.Length; i++)
            {
                if (Second[i] != null)
                {
                    Point q = coords;
                    z = Second[i].GetAllArrows();
                    if (z.Length == 2 && z[0] == this)
                    {
                        q.X = coords.X - z[1].coords.X;
                        q.X = coords.Y - z[1].coords.Y;
                    }
                    if (z.Length == 2 && z[1] == this)
                    {
                        q.X = coords.X - z[0].coords.X;
                        q.X = coords.Y - z[0].coords.Y;
                    }
                    double arc = Math.Acos((s.X * q.X + s.Y * q.Y) / Math.Sqrt((s.X * s.X + s.Y * s.Y) * (q.X * q.X + q.Y * q.Y)));
                    if (arc > 0 && arc < 1)
                    {
                        if (UsedSecond < 1)
                        {
                            UsedSecond++;
                            return true;
                        }
                        if (UsedFitst < 1)
                        {
                            UsedFitst++;
                            return true;
                        }
                    }
                }
            }

            return false;
        }

		public Road[] GetRoad(Road a)
		{
			if(UsedFitst > -1 && a == First[0])
				return Second;
			if(UsedFitst > 0 && a == First[1])
				return Second;
			if(UsedSecond > -1 && a == Second[0])
				return First;
			if(UsedSecond > 0 && a == Second[1])
				return First;
            return new Road[0];
		}

        public Road[] GetRoadPlatform()
        {
            if (UsedFitst != 0)
                return First;
            if (UsedSecond != 0)
                return Second;
            return new Road[0];
        }
	}

}