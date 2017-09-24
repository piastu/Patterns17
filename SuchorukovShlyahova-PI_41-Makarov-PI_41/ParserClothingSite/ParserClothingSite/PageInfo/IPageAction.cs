using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo
{
    public interface IPageAction<Z> where Z : IContainerForBlock<PageSimpleBlock>
    {       
        IEnumerable<Z> GetCollectionBlock(Func<Z, bool> _predicate, Page<Z> _page);
        IEnumerable<Page<Z>> GetIterableChildBlock(Page<Z> _page);
    }
}
