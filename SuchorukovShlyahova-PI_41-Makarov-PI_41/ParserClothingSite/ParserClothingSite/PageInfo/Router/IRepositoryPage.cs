using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo.Router
{
    public interface IRepositoryPage<Z> where Z: IContainerForBlock<PageSimpleBlock>
    {
        IPageManager<Z> pageManager();
        IPageAction<Z> pageAction();
    }
}
