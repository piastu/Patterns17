using ParserClothingSite.GetContentHelper;
using ParserClothingSite.PageInfo;
using ParserClothingSite.PageInfo.Factory;
using ParserClothingSite.Parser;
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ParserClothingSite
{
    class Program
    {
        public static Page<IContainerForBlock<PageTagBlock>> _pageMen;
        public static Parser<IContainerForBlock<PageTagBlock>> _parser;
        public static IPageAction<IContainerForBlock<PageTagBlock>> _pageIterable;
        public static IPageManager<IContainerForBlock<PageTagBlock>> _pageManager;
        static void Main(string[] args)
        {
            _parser = new Parser<IContainerForBlock<PageTagBlock>>(new HtmlSubject(), new SimplePageFactory<IContainerForBlock<PageTagBlock>>());
            _pageIterable = new PageIterableAction();
            _pageManager = new PageManager();
            _pageMen = new SimplePageFactory<IContainerForBlock<PageTagBlock>>().CreatePage(
                new Uri("https://www.lamoda.ru/men-home/?sitelink=topmenuM"), _pageIterable, _pageManager);
            var answer = _parser.GetPageCollection(_pageMen).Result;
            ConcurrentQueue<SubjectInfo> result = new ConcurrentQueue<SubjectInfo>();

            var nChunks = 10;
            var totalLength = answer.Count();
            var chunkLength = (int)Math.Ceiling(totalLength / (double)nChunks);
            var _random = Enumerable.Range(0, 5)
                      .Select(i => answer.Skip(i * chunkLength).Take(chunkLength)).ToList();
            var ans = answer.Take((int)answer.Count / 8);
            try
            {

                foreach (var i in ans)
                {
                    var data = _parser.GetSubjectCollection(i).Result;
                    foreach (var j in data)
                    {
                        result.Enqueue(j);
                    }
                }

            }
            catch (ArgumentOutOfRangeException e)
            {
                Console.WriteLine(e.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine();

        }
    }
}
