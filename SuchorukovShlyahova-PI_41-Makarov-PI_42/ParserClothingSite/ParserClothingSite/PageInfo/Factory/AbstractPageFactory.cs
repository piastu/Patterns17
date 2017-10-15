using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo.Factory
{
    public abstract class AbstractPageFactory<T> where T : IContainerForBlock<PageSimpleBlock>
    {
        public abstract Page<T> CreatePage(Uri _uri,IPageAction<T> _iaction, IPageManager<T> _imanager);
    }
}
