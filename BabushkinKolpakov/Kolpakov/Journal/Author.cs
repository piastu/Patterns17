using System;
namespace Journal
{
    [Serializable]
    public class Author
    {
        //Имя автора
        public string Name { get; set; }
        //Год рождения
        public int BirthYear { get; set; }
        //Должность
        public string Position { get; set; }
        //Индекс цитирования Хирша
        public int HIndex { get; set; }
        //Общее количество публикаций
        public int PublicationsCount { get; set; }
    }
}
