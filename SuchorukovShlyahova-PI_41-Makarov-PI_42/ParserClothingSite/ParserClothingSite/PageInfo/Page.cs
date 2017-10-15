using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo
{
    public class Page<Z> where Z : IContainerForBlock<PageSimpleBlock>
    {
        public Uri CurrentUri { get; private set; }
        public IPageAction<Z> pageAction { get; private set; }
        public IPageManager<Z> pageManager { get; private set; }
        public List<Page<Z>> ChildrenPage { get; private set; }
        public List<Z> Block { get; private set; }
        public Page(Uri _Uri, IPageAction<Z> _pageAction, IPageManager<Z> _pageManager)
        {
            pageAction = _pageAction;
            pageManager = _pageManager;
            CurrentUri = _Uri;
            Block = new List<Z>();
            ChildrenPage = new List<Page<Z>>();
        }
        public void AddChildPage(Page<Z> _icontainer)
        {
            pageManager.AddChildPage(ChildrenPage, _icontainer);
        }
        public async Task<bool> RemoveChildPage(Page<Z> _icontainer)
        {
            return await pageManager.RemoveChildPage(ChildrenPage, _icontainer);
        }
        public void AddBlock(Z _icontainer)
        {
            pageManager.AddBlock(Block, _icontainer);
        }
        public async Task<bool> RemoveBlock(Z _icontainer)
        {
            return await pageManager.RemoveBlock(Block, _icontainer);
        }

    }

}
