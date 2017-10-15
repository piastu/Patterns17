using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo
{
    public interface IContainerForBlock<out TypeContainer> where TypeContainer : PageSimpleBlock
    {
        /// <summary>
        /// Element in the validation or Exception
        /// </summary>
        /// <returns>Type of PageSimpleBlock</returns>
        TypeContainer CheckElement();
        /// <summary>
        /// Return PageSimpleBlock from Container
        /// </summary>
        /// <returns>Type of PageSimpleBlock</returns>
        TypeContainer GetElement();
    }
}
