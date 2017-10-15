using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.GetContentHelper
{
    public interface IGetHtmlContent
    {
        Task<string> GetContentAsync(string url);
        string GetContent(string url);
    }
}
