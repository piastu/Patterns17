using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TelegramBot.TelegramSubject;
using static TelegramBot.EventTypes.EventType;

namespace TelegramBot.EventTypes.EventFactory
{
    public abstract class AbstractEventFactory
    {
        public abstract MessageText<User, Chat> CreateMessageTextEvent(JSONNode _node);
        public abstract MessageSticker<User, Chat> CreateMessageStickerEvent(JSONNode _node);
        public abstract MessagePhoto<User, Chat> CreateMessagePhotoEvent(JSONNode _node);
        public abstract MessageVideo<User, Chat> CreateMessageVideoEvent(JSONNode _node);
        public abstract MessageDocument<User, Chat> CreateMessageDocumentEvent(JSONNode _node);
        public abstract MessageLocation<User, Chat> CreateMessageLocationEvent(JSONNode _node);
        public abstract MessageContact<User, Chat> CreateMessageContactEvent(JSONNode _node);
        public abstract MessageVoice<User, Chat> CreateMessageVoiceEvent(JSONNode _node);
    }
}
