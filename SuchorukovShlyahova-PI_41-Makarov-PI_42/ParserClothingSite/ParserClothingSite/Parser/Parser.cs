using AngleSharp.Parser.Html;
using Ninject;
using ParserClothingSite.GetContentHelper;
using ParserClothingSite.PageInfo;
using ParserClothingSite.PageInfo.Factory;
using ParserClothingSite.PageInfo.Router;
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace ParserClothingSite.Parser
{
    public class Parser<T> : IHtmlParser<T>, IDisposable where T : IContainerForBlock<PageTagBlock>
    {
        private IGetHtmlContent htmlSubject;
        private IPageManager<T> _ipageManger;
        private IPageAction<T> _ipageAction;
        private IKernel _Kernal;
        private AbstractPageFactory<T> _simpleFactory;
        private ConcurrentQueue<string> collectionConcurrent;
        public Parser(IGetHtmlContent _htmlSubject, AbstractPageFactory<T> _factory)
        {
            collectionConcurrent = new ConcurrentQueue<string>();
            _simpleFactory = _factory;
            _Kernal = new StandardKernel();
            _Kernal.Load(Assembly.GetExecutingAssembly());
            _ipageManger = (_Kernal.Get<PageManager>() as IPageManager<T>);
            _ipageAction = (_Kernal.Get<PageIterableAction>() as IPageAction<T>);
            htmlSubject = _htmlSubject;
        }


        private Task<IEnumerable<Page<T>>> GetFacadePageCollection(string url)
            => Enumerable.Range(0, 1)
            .Select(async _ => await htmlSubject.GetContentAsync(url))
                .Select(async content =>
                {
                    HtmlParser _parser = new HtmlParser();
                    var _document = _parser.Parse(await content);
                    return _document.QuerySelectorAll("div[class='menu__category-trigger  '] > a")
                    .SelectMany(s => s.Attributes.Where(i => i.Name == "data-link"))
                    .Select(i => _simpleFactory.CreatePage(new Uri(PrefixRouter.lamoda + i.Value), _ipageAction, _ipageManger));
                }
                ).First();

        private IEnumerable<string> CreateUriForAllTag(string mainpage, int countpage, string delimiter)
            => Enumerable.Range(1, countpage).Select(page =>
            {
                return mainpage + delimiter + "page=" + page;
            });

        private Task<IEnumerable<string>> GetPageFromUrl(string url, string delimetr)
           => Enumerable.Range(0, 1)
          .Select(async _ => await htmlSubject.GetContentAsync(url))
              .Select(async content =>
              {
                  int countpage = 0;
                  Regex regex = new Regex(@"\d{1,5}(?=\S\WperPage)");

                  Match match = regex.Match(await content);
                  while (match.Success)
                  {
                      Int32.TryParse(match.Value, out countpage);
                      match = match.NextMatch();
                  }
                  return CreateUriForAllTag(url, countpage, delimetr);
              }).First();


        public async Task<ConcurrentQueue<string>> GetPageCollection(Page<T> page, string delimetr = "&")
        {
            var _facadepage = await GetFacadePageCollection(page.CurrentUri.AbsoluteUri);
            var _element = (_facadepage.Skip(2).Take(1).ToList()[0] as Page<T>);
            var _collection = await (GetChildrenPageCollection(_element.CurrentUri.AbsoluteUri));




            var _pagetasks = (from item in _collection select GetPageFromUrl(item.CurrentUri.AbsoluteUri, "?")).ToList();
            while (_pagetasks.Count > 0)
            {
                try
                {
                    var task = await Task.WhenAny(_pagetasks);
                    _pagetasks.Remove(task);
                    var _pages = await task;
                    foreach (var i in _pages)
                    {
                        collectionConcurrent.Enqueue(i);
                    }
                }
                catch (AggregateException ae)
                {
                    ae = ae.Flatten();
                }
                catch (Exception ex)
                {

                }
            }
            return collectionConcurrent;


        }

        private Task<IEnumerable<Page<T>>> GetChildrenPageCollection(string url)
            => Enumerable.Range(0, 1)
            .Select(async _ => await htmlSubject.GetContentAsync(url))
            .Select(async content =>
            {

                HtmlParser _parser = new HtmlParser();
                var _document = _parser.Parse(await content);
                return _document.QuerySelectorAll("ul[class='cat-nav show'] > li  ul  li")
                .SelectMany(item => item.Children)
                 .SelectMany(it => it.Attributes.Where(attribute => attribute.Name == "href"))
                .Select(attribute => _simpleFactory.CreatePage(new Uri(PrefixRouter.lamoda + attribute.Value ?? ""), _ipageAction, _ipageManger));
            }).First();

        private Task<IEnumerable<SubjectInfo>> ParseHtmlPageAsync(string url)
          => Enumerable.Range(0, 1)
              .Select(async _ => await htmlSubject.GetContentAsync(url))
          .Select(async content =>
          {

              HtmlParser _parser = new HtmlParser();
              var document = _parser.Parse(await content);
              var firsthreftag = document.QuerySelectorAll("div[class='products-catalog__list'] > div[class='products-list-item']"); 
              var hreftag = document.QuerySelectorAll("div[class='products-list-item m_loading']");
              var child = hreftag.SelectMany(it => it.Children)
              .SelectMany(item => item.Attributes.Where(attribute => attribute.Name == "href"));

              var firstchild = firsthreftag.SelectMany(it => it.Children)
              .SelectMany(item => item.Attributes.Where(attribute => attribute.Name == "href"));

              var data = firstchild.ToList();
              if(child.ToList().Count > 0 )
              {
                  data.AddRange(child);
              }
              

              var pricetag = document.QuerySelectorAll("div[class='to-favorites js-to-favorites']");
              var attr = pricetag.SelectMany(it => it.Attributes);
              var img = attr.Where(attribute => attribute.Name == "data-image");
              var price = attr.Where(attribute => attribute.Name == "data-price");

              if (data.Count > 0)
              {
                  return data.Select((element, index) =>
                   new SubjectInfo
                   {
                       Price = price.ElementAt(index).Value,
                       HrefImage = img.ElementAt(index).Value,
                       Href = PrefixRouter.lamoda + element.Value
                   });
              }

              return new List<SubjectInfo>();

          }).First();


        public Task<IEnumerable<SubjectInfo>> GetSubjectCollection(string url)
         => Enumerable.Range(0, 1).
            Select(async _ => await this.ParseHtmlPageAsync(url))
            .Select(async content =>
            {
                var turn = await content;
                return turn.Select(item => item);
            }).First();

        public void Dispose()
        {

            Dispose(true);
            GC.SuppressFinalize(this);
        }
        ~Parser()
        {

            Dispose(false);
        }
        protected virtual void Dispose(bool disposing)
        {
            if (disposing)
            {
                IDisposable disposable = _Kernal as IDisposable;
                if (disposable != null)
                {
                    disposable.Dispose();
                }
                _Kernal = null;
            }
            // free native resources if there are any.             
        }
    }

}
