using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TelegramBot.TelegramSubject;

namespace TelegramBot.EventTypes.FactoryEvent
{
    public class StandartFactoryEvent<U, C> : AbstractFactoryEvent where U : User where C : Chat
    {
        public override EventArgs CreateMessageEvent()
        {
            return new EventType.MessageText<U, C>();
        }

        public override EventArgs CreateMessageStricerEvent()
        {
            throw new NotImplementedException();
        }
    }
}
