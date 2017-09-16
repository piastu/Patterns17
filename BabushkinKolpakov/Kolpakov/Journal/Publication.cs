using System;
using System.Collections.Generic;
namespace Journal
{
    [Serializable]
    public abstract class Publication
    {
        //Название публикации
        public string Name { get; set; }
        //Количество страниц
        public int PageCount { get; set; }
        //Дата публикации
        public DateTime Date { get; set; }
        //Что цитирует публикация
        public List<Publication> Citates { get; set; }

        public Publication()
        {
            Citates = new List<Publication>();
        }
    }
    //Статья
    [Serializable]
    class Article : Publication
    {
        //Число читателей
        public int ReadersCount { get; set; }
    }
    //Книга
    [Serializable]
    class Book : Publication
    {
        //Серийный номер
        public int ISBN { get; set; }
    }
    //Монография
    [Serializable]
    class Monography : Publication
    {
        //Тема
        public string Theme { get; set; }
    }
}
