using ParserClothingSite.PageInfo;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.Parser
{
    public class NinjectBindings : Ninject.Modules.NinjectModule
    {
        public override void Load()
        {
            Bind(typeof(IPageManager<>)).To(typeof(PageManager))
                .When(r=> typeof(IContainerForBlock<PageSimpleBlock>).IsAssignableFrom(r.Service.GetGenericArguments()[0]));
            Bind(typeof(IPageAction<>)).To(typeof(PageIterableAction))
                .When(r => typeof(IContainerForBlock<PageSimpleBlock>).IsAssignableFrom(r.Service.GetGenericArguments()[0]));
        }
    }
}
