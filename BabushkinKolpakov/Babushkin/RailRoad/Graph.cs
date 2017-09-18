using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RailRoad
{
    [Serializable()]
    public class Graph
    {
		public Station Start;                                          // станция начало
        public Station Finish;                                         // станция конец
        public int n;
        public double Inf;                                             // бесконечность
        public Dictionary<Arrow, double> minL;                         // минимальная дистанция до точки
        public Dictionary<Arrow, Arrow> prevA;                         // вершина из которой пришли
        public Dictionary<Arrow, Road> prevR;                          // путь из которого пришли
        public List<KeyValuePair<Arrow, double>> previewMin;           // обход графа
        public HashSet<Road> disable;                                  // запрещеные пути
        public HashSet<Arrow> StartArrows;                             // стартовые вершины 
        public Arrow finished;                                         // конечная вершина
        public List<List<KeyValuePair<int, double>>> g;
        public Dictionary<Arrow, int> AtoI;
        public Dictionary<int, Arrow> ItoA;
        public string Name;                                            // низвание маршрута
        public Train ThisTrain;                                        // поезд осуществляющий маршрут
        public DateTime StartDate;                                     // дата начала
        public DateTime FinishDate;                                    // дата конца
        public double CruiserSpeed;                                    // курсовая скорость
        public DateTime TimeLenght;                                    // время в пути фактичаское
        public double Lenght;                                          // длина пути

		public Graph()
		{

            Inf = Double.PositiveInfinity;
            g = new List<List<KeyValuePair<int, double>>>();
            n = 0;
            AtoI = new Dictionary<Arrow, int>();
            ItoA = new Dictionary<int, Arrow>();
		}

        public Graph(Station start, Station finish)
		{
			Start = start;
			Finish = finish;

            Inf = Double.PositiveInfinity;
		}
        
        private int comp(KeyValuePair<Arrow, double> a,KeyValuePair<Arrow, double>b)
        {
            if (a.Value == b.Value)
                return 0;
            else if (a.Value < b.Value)
                return -1;
            else return 1;
        }

        private List<int> Dijkstra(int s,int t)
        {
            List<double> d;
            List<int>p;
            d = new List<double>();
            p = new List<int>();
            List<bool> u = new List<bool>();
            for(int i = 0 ; i < n; i++)
            {
                d.Add(Inf);
                p.Add(0);
                u.Add(false);
            }
	        d[s] = 0;
	        for (int i=0; i<n; ++i) {
		        int v = -1;
		        for (int j=0; j<n; ++j)
			        if (!u[j] && (v == -1 || d[j] < d[v]))
				        v = j;
		        if (d[v] == Inf)
			        break;
		        u[v] = true;
 
		        for (int j=0; j<g[v].Count; ++j) {
                    int to = g[v][j].Key;
				    double len = g[v][j].Value;
			        if (d[v] + len < d[to]) {
				        d[to] = d[v] + len;
				        p[to] = v;
			        }
		        }
	        }
            List<int> path = new List<int>();
            for (int v = t; v != s; v = p[v])
                path.Add(v);
            path.Add(s);
            path.Reverse();
            return path;
        }

        private bool Dijkstra1()
		{
            minL = new Dictionary<Arrow, double>();
            prevA = new Dictionary<Arrow, Arrow>();
            prevR = new Dictionary<Arrow, Road>();
            previewMin = new List<KeyValuePair<Arrow, double>>();

            Arrow[] s = Start.GetArrow();
            Road[] temp;
            Arrow th;
            KeyValuePair<Arrow, double> tr;

            foreach (Arrow item in s)
            {
                StartArrows.Add(item);
                minL.Add(item, 0);
                temp = item.GetRoadPlatform();
                foreach (Road j in temp)
                {
                    if (!disable.Contains(j))
                    {
                        th = j.GetArrow(item);
                        minL[th] = j.Lenght;
                        previewMin.Add(new KeyValuePair<Arrow, double>(th, j.Lenght));
                        prevA[th] = item;
                        prevR[th] = j;
                    }
                }
            }
            while(previewMin.Count != 0)
            {
                previewMin.Sort(comp);
                tr = previewMin[0];
                temp = tr.Key.GetRoad(prevR[tr.Key]);
                for(int i = 0 ; i < temp.Length;i++)
                {
                    if (!disable.Contains(temp[i]))
                    {
                        th = temp[i].GetArrow(tr.Key);
                        if (minL.ContainsKey(th))
                        {
                            if (minL[tr.Key] + temp[i].Lenght < minL[th])
                            {
                                int z = previewMin.IndexOf(new KeyValuePair<Arrow, double>(th, minL[th]));
                                if (z > -1)
                                {
                                    previewMin[z] = new KeyValuePair<Arrow, double>(th, minL[tr.Key] + temp[i].Lenght);
                                }
                                minL[th] = minL[tr.Key] + temp[i].Lenght;
                                prevA[th] = tr.Key;
                                prevR[th] = temp[i];
                            }
                        }
                        else
                        {
                            minL[th] = minL[tr.Key] + temp[i].Lenght;
                            prevA[th] = tr.Key;
                            prevR[th] = temp[i];
                        }
                    }
                }
            }
            s = Finish.GetArrow();
            double minn = Inf;
            int qq = -1;
            for(int i = 0 ; i < s.Length; i++)
            {
                if(minL.ContainsKey(s[i]))
                {
                    if(minn > minL[s[i]])
                    {
                        minn = minL[s[i]];
                        qq = i;
                    }
                }
            }
            finished = s[qq];
            if(qq == -1)
            {
                finished = null;
                return false;
            }
            else
            {
                finished = s[qq];
                return true;
            }
		}

        private ListRoad getList()
        {
            Arrow th = finished;
            ListRoad res = new ListRoad();
            res.add(Finish);
            while(!StartArrows.Contains(th))
            {
                res.add(th);
                res.add(prevR[th]);
                th = prevA[th];
            }
            res.add(th);
            res.add(Start);
            return res;
        }

        public void addVertex(Arrow q){
            ItoA[g.Count] = q;
            AtoI[q] = g.Count;
            g.Add(new List<KeyValuePair<int, double>>());
            n = g.Count;
        }

        public void addEdge(Arrow q,Arrow w, double l)
        {
            g[AtoI[q]].Add(new KeyValuePair<int,double>(AtoI[w],l));
            g[AtoI[w]].Add(new KeyValuePair<int, double>(AtoI[q], l));
        }

        private List<Arrow> intToArr(List<int> q)
        {
            List<Arrow> res = new List<Arrow>();
            for(int i = 0; i < q.Count ; i++)
            {
                res.Add(ItoA[q[i]]);
            }
            return res;
        }

        public void addEdge(int q, int w, double l)
        {
            g[q].Add(new KeyValuePair<int, double>(w, l));
            g[w].Add(new KeyValuePair<int, double>(q, l));
        }

        private void delEdge(int s,int f)
        {
            for(int i = 0 ; i < g[s].Count; i++)
            {
                if(g[s][i].Key == f)
                {
                    g[s].Remove(g[s][i]);
                    i--;
                }
            }
            for (int i = 0; i < g[f].Count; i++)
            {
                if (g[f][i].Key == s)
                {
                    g[f].Remove(g[f][i]);
                    i--;
                }
            }
        }

        private double length(List<int> q)
        {
            double res = 0;
            for(int i = 0 ; i < q.Count - 1; i++)
            {
                for(int j = 0; j < g[q[i]].Count; j++)
                {
                    if (g[q[i]][j].Key == q[i+1])
                    {
                        res += g[q[i]][j].Value;
                    }
                }
            }
            return res;
        }

        private double length(int q, int w)
        {
            double res = 0;
            for (int i = 0; i < g[q].Count; i++)
            {
                if (g[q][i].Key == w)
                    return g[q][i].Value;
            }
            return res;
        }

        public List<Route> getListsRoad(int n)
        {
            int s, f;
            s = AtoI[Start.GetArrow()[0]];
            f = AtoI[Finish.GetArrow()[0]];
            List<int> fifi = Dijkstra(s, f);
            List<int> newfifi ;
            List<int> qeqe;
            List<Route> res = new List<Route>();
            res.Add(new Route(intToArr(fifi)));
            res[res.Count - 1].Lenght = length(fifi);
            res[res.Count - 1].ThisTrain = ThisTrain;
            res[res.Count - 1].Name = Name;
            res[res.Count - 1].StartDate = StartDate;
            res[res.Count - 1].CalcTime();
            res[res.Count - 1].Start = Start;
            res[res.Count - 1].Finish = Finish;
            List<List<KeyValuePair<int, double>>> save = new List<List<KeyValuePair<int,double>>>(g);

            for (int k = 1; k < n;k++ )
            {
                double min = Inf;
                newfifi = new List<int>();
                int thisS = -1;
                int thisF = -1;
                for(int i = 0 ; i < fifi.Count - 1; i++)
                {
                    double l = length(fifi[i], fifi[i + 1]);
                    delEdge(fifi[i], fifi[i + 1]);
                    
                    qeqe = Dijkstra(s, f);
                    if (min >= length(qeqe) && length(qeqe) != 0)
                    {
                        min = length(qeqe);
                        newfifi = qeqe;
                        thisS = s;
                        thisF = f;
                    }
                    addEdge(fifi[i], fifi[i + 1], l);
                }
                res.Add(new Route(intToArr(newfifi)));
                res[res.Count - 1].Lenght = length(newfifi);
                res[res.Count - 1].ThisTrain = ThisTrain;
                res[res.Count - 1].Name = Name;
                res[res.Count - 1].StartDate = StartDate;
                res[res.Count - 1].CalcTime();
                res[res.Count - 1].Start = Start;
                res[res.Count - 1].Finish = Finish;
                if(thisS != -1)
                {
                    delEdge(thisS, thisF);
                }
                fifi = newfifi;
            }
            return res;
        }

	}

}