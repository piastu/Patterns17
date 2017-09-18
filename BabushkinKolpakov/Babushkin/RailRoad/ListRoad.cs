using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RailRoad
{
    [Serializable()]
    class ListRoad
    {
        public List<ObjectRoad> ListRoads;
        public int i = 0;

        public ListRoad()
        {
            ListRoads = new List<ObjectRoad>();
        }

        public void add(ObjectRoad a)
        {
            ListRoads.Add(a);
        }

        public ObjectRoad getNext()
        {
            if(ListRoads.Count == 0)
                return null;
            i++;
            if(i >= ListRoads.Count)
            {
                i = 0;
            }
            return ListRoads[i];
        }

        public List<ObjectRoad> getlist()
        {
            return ListRoads;
        }
    }
}
