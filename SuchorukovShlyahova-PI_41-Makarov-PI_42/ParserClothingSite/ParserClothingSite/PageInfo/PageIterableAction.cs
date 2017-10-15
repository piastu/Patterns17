using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo
{
    //kill me plz, may be ioc. 
    public class PageIterableAction : IPageAction<IContainerForBlock<PageTagBlock>>
    {
        public IEnumerable<IContainerForBlock<PageTagBlock>> GetCollectionBlock(Func<IContainerForBlock<PageTagBlock>, bool> _predicate, Page<IContainerForBlock<PageTagBlock>> _page)
        {
            foreach (var e in _page.Block)
            {
                yield return e;
            }
        }

        public IEnumerable<Page<IContainerForBlock<PageTagBlock>>> GetIterableChildBlock(Page<IContainerForBlock<PageTagBlock>> _page)
        {
            foreach (var e in _page.ChildrenPage)
            {
                yield return e;
            }
        }
    }
}
