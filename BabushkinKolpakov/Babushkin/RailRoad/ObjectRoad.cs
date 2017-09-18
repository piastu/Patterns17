using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace RailRoad
{
    [Serializable()]
    public abstract class ObjectRoad
    {
        public Int64 id; // уникальный индефикатор
        public Point coords; // коодинаты объекта 

        public Int64 ID
        {
            get
            {
                return id;
            }
        }

        public Point Coord
        {
            get
            {
                return coords;
            }
            set
            {
                coords = value;
            }
        }

        public ObjectRoad()
        {
            id = -1;
            coords = new Point(0, 0);
        }
        public ObjectRoad(Int64 _id,  Point _coords)
        {
            id = _id;
            coords = _coords;
        }
    }
}
