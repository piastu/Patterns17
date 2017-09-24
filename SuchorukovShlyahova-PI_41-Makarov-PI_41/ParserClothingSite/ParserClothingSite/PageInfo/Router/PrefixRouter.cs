using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo.Router
{
    public class PrefixRouter
    {
        private readonly String name;
        private readonly int value;
        public static readonly PrefixRouter lamoda = new PrefixRouter(1, "https://www.lamoda.ru");
        private PrefixRouter(int value, String name)
        {
            this.name = name;
            this.value = value;
        }

        public override String ToString()
        {
            return name;
        }
    }
}
