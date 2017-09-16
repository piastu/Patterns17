using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
namespace Journal
{
    static class Utils
    {
        //Запись объекта в файл
        public static void WriteToBinaryFile<T>(string filePath, T objectToWrite, bool append = false)
        {
            using (Stream stream = File.Open(filePath, append ? FileMode.Append : FileMode.Create))
            {
                var binaryFormatter = new System.Runtime.Serialization.Formatters.Binary.BinaryFormatter();
                binaryFormatter.Serialize(stream, objectToWrite);
            }
        }
        //Чтение из объекта из файла
        public static T ReadFromBinaryFile<T>(string filePath)
        {
            using (Stream stream = File.Open(filePath, FileMode.Open))
            {
                var binaryFormatter = new System.Runtime.Serialization.Formatters.Binary.BinaryFormatter();
                return (T)binaryFormatter.Deserialize(stream);
            }
        }
        //Получение случайного элемента коллекции
        public static T Sample<T>(this IEnumerable<T> e, Random r)
        {
            return e.OrderBy(x => r.Next()).FirstOrDefault();
        }
        //Получение значения из словаря или значения по умолчанию если ключ не найден
        public static TValue GetValueOrDefault<TKey, TValue>
            (this IDictionary<TKey, TValue> dictionary,
            TKey key,
            TValue defaultValue)
        {
            TValue value;
            return dictionary.TryGetValue(key, out value) ? value : defaultValue;
        }
        public static HashSet<T> ToHashSet<T>(this IEnumerable<T> enumerable)
        {
            HashSet<T> hs = new HashSet<T>();
            foreach (T item in enumerable)
                hs.Add(item);
            return hs;
        }
        //Поиск элемента в коллекции связи, характеристика которого наибольшее
        public static Tuple<T1, int> MaxCountsBy<T1, T2>
            (this IEnumerable<Tuple<T1, T2>> e,
            Func<T1, T2, int> characteristic)
        {
            var d = new Dictionary<T1, int>();
            int max = 0, c;
            T1 maxEl = default(T1), el;
            foreach (var t in e)
            {
                el = t.Item1;
                c = d.GetValueOrDefault(el, 0) + characteristic(el, t.Item2);
                if (c > max)
                {
                    max = c;
                    maxEl = el;
                }
                d[el] = c;
            }
            return Tuple.Create(maxEl, max);
        }
    }
    public class Ref<T>
    {
        public T _;
        public Ref(T v) { _ = v; }
        public static Ref<T> __(T v){ return new Ref<T>(v);}
    }
}
