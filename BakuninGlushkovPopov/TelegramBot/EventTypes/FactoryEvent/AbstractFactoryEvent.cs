using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TelegramBot.EventTypes.FactoryEvent
{
    public abstract class AbstractFactoryEvent
    {
        public abstract EventArgs CreateMessageEvent();
        public abstract EventArgs CreateMessageStricerEvent();
    }
}
