using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo.Factory
{
    public class SimplePageFactory<T> : AbstractPageFactory<T> where T: IContainerForBlock<PageSimpleBlock>
    {
        public override Page<T> CreatePage(Uri _uri, IPageAction<T> _iaction, IPageManager<T> _imanager)
        {
            return new Page<T>(_uri, _iaction, _imanager);
        }
    }
}
