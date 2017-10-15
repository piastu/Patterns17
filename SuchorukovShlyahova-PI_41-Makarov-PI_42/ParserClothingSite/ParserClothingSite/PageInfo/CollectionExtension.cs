using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo
{
    public static class CollectionExtension
    {
        public static IEnumerable<IEnumerable<T>> Split<T>(
                    this IEnumerable<T> source,
                                int count)
        {
            return source
              .Select((x, y) => new { Index = y, Value = x })
              .GroupBy(x => x.Index / count)
              .Select(x => x.Select(y => y.Value).ToList())
              .ToList();
        }
    }
}
