using ParserClothingSite.PageInfo;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.Parser
{
    public interface IHtmlParser<T> where T: IContainerForBlock<PageSimpleBlock>
    {
        Task<IEnumerable<SubjectInfo>> GetSubjectCollection(string url);

    }
}
