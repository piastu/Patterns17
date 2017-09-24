using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo.Router
{
    public class FacadePage<Z> : IRepositoryPage<Z> where Z : IContainerForBlock<PageSimpleBlock>
    {
        public IPageAction<Z> pageAction()
        {
            throw new NotImplementedException();
        }

        public IPageManager<Z> pageManager()
        {
            throw new NotImplementedException();
        }
    }
}
