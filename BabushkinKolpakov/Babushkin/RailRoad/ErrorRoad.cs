using System;

namespace RailRoad
{

///
/// <summary> * Created by IDIB on 23.10.2015. </summary>
/// 
    [Serializable()]
	public class ErrorRoad
	{
		internal int Type; // тип ошибки

		public ErrorRoad()
		{
		}

		public override string ToString()
		{
			string mes;
			switch (Type)
			{
				case 0:
					mes = "Путь не найден";
					break;
                case 1:
                    mes = "Одна из точек дороги не найдена";
                    break;
                case 2:
                    mes = "обект с таким ID уже есть";
                    break;
				default:
					mes = "Неизвестная ошибка";
					break;
			}
			return mes;
		}

		public ErrorRoad(int type)
		{
			Type = type;
		}


	}

}