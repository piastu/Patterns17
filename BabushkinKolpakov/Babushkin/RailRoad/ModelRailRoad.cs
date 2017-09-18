using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Collections.ObjectModel;
using System.ComponentModel;

namespace RailRoad
{
    [Serializable()]
    public class ModelRailRoad 
    {
        public Int64  ids = 0;
        public Int64 NextID
        {
            get
            {
                ids++;
                return ids - 1; 
            }
        }

        public List<Road> LRoad;
        public List<Station> LStation;
        public List<Route> LRoute;
        public List<Arrow> LArrow;
        public List<Train> LTrain;
        public List<ErrorRoad> LError;

        public Graph G;

        public ModelRailRoad()
        {
            LRoad = new List<Road>();
            LStation = new List<Station>();
            LRoute = new List<Route>();
            LArrow = new List<Arrow>();
            LTrain = new List<Train>();
            LError = new List<ErrorRoad>();
            G = new Graph();
        }

        public bool addRoad(Road t)
        {
            Arrow[] temp = t.GetAllArrows();
            bool fl = true;
            if(findID(t.ID))
            {
                LError.Add(new ErrorRoad(2));
            }
            for (int i = 0; i < temp.Length && fl; i++)
            {
                int q = LArrow.IndexOf(temp[i]);
                if (q< 0)
                {
                    fl = false;
                    LError.Add(new ErrorRoad(1));
                }else{
                    fl = LArrow[q].TryPick(t);
                }
            }
            if(fl)
            {
                for (int i = 0; i < temp.Length && fl; i++)
                {
                    int q = LArrow.IndexOf(temp[i]);
                    if (q >= 0)
                    {
                        LArrow[q].Add(t);
                    }
                }

            }
            return fl;
        }

        public bool addRoad(int a,int b,double lens,bool z)
        {

            Road t = new Road(NextID, LArrow[a].Coord, LArrow[a], LArrow[b], lens );
            Arrow[] temp = t.GetAllArrows();
            bool fl = true;
            if (findID(t.ID))
            {
                LError.Add(new ErrorRoad(2));
            }
            for (int i = 0; i < temp.Length && fl; i++)
            {
                int q = LArrow.IndexOf(temp[i]);
                if (q < 0)
                {
                    fl = false;
                    LError.Add(new ErrorRoad(1));
                }
                else
                {
                    fl = LArrow[q].TryPick(t);
                }
            }
            LRoad.Add(t);
            G.addEdge(LArrow[a], LArrow[b], t.Lenght);
            for (int i = 0; i < temp.Length && fl; i++)
            {
                int q = LArrow.IndexOf(temp[i]);
                if (q >= 0)
                {
                    LArrow[q].Add(t);
                }
            }
            return fl;
        }

        public void addArrow(Arrow t)
        {
            LArrow.Add(t);
        }

        public void addArrow(Point t)
        {
            LArrow.Add(new Arrow(NextID,t));
            G.addVertex(LArrow[LArrow.Count - 1]);
        }

        public bool addStation(Station t)
        {
            LStation.Add(t);
            return false;
        }

        public bool addStation(String name,int q, int r)
        {
            Station t = new Station(NextID, LArrow[q], r);
            t.Name = name;
            LStation.Add(t);
            return true;
        }

        public bool findID(Int64 _id)
        {
            bool fl = false;
            foreach (Road i in LRoad)
            {
                if (i.ID == _id)
                {
                    fl = true;
                    break;
                }
            }
            if(!fl)
            foreach (Station i in LStation)
            {
                if (i.ID == _id)
                {
                    fl = true;
                    break;
                }
            }
            if (!fl)
            foreach (Route i in LRoute)
            {
                if (i.ID == _id)
                {
                    fl = true;
                    break;
                }
            }
            if (!fl)
            foreach (Arrow i in LArrow)
            {
                if (i.ID == _id)
                {
                    fl = true;
                    break;
                }
            }
            if (!fl)
            foreach (Train i in LTrain)
            {
                if (i.ID == _id)
                {
                    fl = true;
                    break;
                }
            }
            return fl;
        }

        public int getGetArrowsStr()
        {
            return LArrow.Count;
        }

        public List<string> getGetStationStr()
        {
            List<string> q = new List<string>();
            for(int i = 0; i< LStation.Count; i++)
            {
                q.Add(LStation[i].Name);
            }
            return q;
        }

        public List<string> getGetTrainStr()
        {
            List<string> q = new List<string>();
            for (int i = 0; i < LTrain.Count; i++)
            {
                q.Add(LTrain[i].Name);
            }
            return q;
        }

        public List<string> getGetRouteStr()
        {
            List<string> q = new List<string>();
            for (int i = 0; i < LRoute.Count; i++)
            {
                q.Add(LRoute[i].toStr());
            }
            return q;
        }


        public List<Road> getRoads()
        {
            return LRoad;
        }
        public List<Station> getStations()
        {
            return LStation;
        }
        public List<Arrow> getArrows()
        {
            return LArrow;
        }

        public List<Route> FindRoute(string str, int s, int f, int n,  DateTime tims, int tt)
        {
            G.Start = LStation[s];
            G.Finish = LStation[f];
            Train tra = LTrain[tt];
            G.Name = str;
            G.ThisTrain = tra;
            G.StartDate = tims;
            return G.getListsRoad(n);
        }

        public void AddRoute(Route a)
        {
            LRoute.Add(a);
        }

        public void AddTrain(string m,double q)
        {
            LTrain.Add(new Train(NextID, m, q));
        }
    }
}
