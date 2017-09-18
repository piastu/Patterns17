using System;
using System.Collections.Generic;

namespace RailRoad
{
///
/// <summary> * Created by IDIB on 27.09.2015. </summary>
/// 
    [Serializable()]
	public class Train
	{
        public Int64 id; // уникальный индефикатор
        public string Name; // имя
        public double Mileage; // пробег
        public double SpeedMax; // максимальная скорость
		public double SpeedCruiser; // курсовая скорость

        public Int64 ID
        {
            get
            {
                return id;
            }
        }

        public Train()
        {

        }

        public Train(Int64 _id,string name, double speed)
        {
            id = _id;
            Name = name;
            SpeedCruiser = speed;
            SpeedMax = speed * 1.3;
        }
	}

}