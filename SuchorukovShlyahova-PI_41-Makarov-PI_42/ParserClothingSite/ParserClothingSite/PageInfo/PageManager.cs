using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo
{
    public class PageManager : IPageManager<IContainerForBlock<PageTagBlock>>
    {
        public void AddBlock(List<IContainerForBlock<PageTagBlock>> _page, IContainerForBlock<PageTagBlock> _icontainer)
        {
            _page.Add(_icontainer);
        }

        public void AddChildPage(List<Page<IContainerForBlock<PageTagBlock>>> _page, Page<IContainerForBlock<PageTagBlock>> _item)
        {
            _page.Add(_item);
        }

        public async Task<bool> RemoveBlock(List<IContainerForBlock<PageTagBlock>> _page, IContainerForBlock<PageTagBlock> _icontainer)
        {
            return  await Task.Factory.StartNew( () => _page.Remove(_icontainer));
        }

        public async Task<bool> RemoveChildPage(List<Page<IContainerForBlock<PageTagBlock>>> _page, Page<IContainerForBlock<PageTagBlock>> _item)
        {
            return await Task.Factory.StartNew(() => _page.Remove(_item));
        }
    }
}
