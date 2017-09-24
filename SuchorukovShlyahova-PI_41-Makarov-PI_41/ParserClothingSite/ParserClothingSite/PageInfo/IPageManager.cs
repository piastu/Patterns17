using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo
{
    public interface IPageManager<Z>  where Z : IContainerForBlock<PageSimpleBlock>
    {
        void AddChildPage(List<Page<Z>> _page , Page<Z> _item);
        Task<bool> RemoveChildPage(List<Page<Z>> _page, Page<Z> _item);
        void AddBlock(List<Z> _page, Z _icontainer);
        Task<bool> RemoveBlock(List<Z> _page,  Z _icontainer);
    }
}
