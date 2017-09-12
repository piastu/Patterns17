using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TelegramBot.TelegramSubject;

namespace TelegramBot.EventTypes
{
    public class EventType
    {
        public class DefaultParameters<U,C> where U: User where C: Chat
        {
            public int MessageId { get; set; }
            public U From { get; set; }
            public C Chat { get; set; }
            public DateTime DateReveiver { get; set; }
        }
        public class DefaultMultiMediaMessageParameters
        {
            public string File_id { get; set; }
            public int Width { get; set; }
            public int Height { get; set; }
            public PhotoSize Thumb { get; set; }
            public int File_size { get; set; }
        }

        #region Классы Типов
        public class MessageText<U, C> : EventArgs where U : User where C : Chat
        {
            public DefaultParameters<U, C> DefaultMessageInfo { get; set; }
            public string Text { get; set; }
        }
        public class MessagePhoto<U,C> : EventArgs where U : User where C : Chat
        {
            public DefaultParameters<U,C> DefaultMessageInfo { get; set; }
            public List<PhotoSize> PhotoCollection { get; set; }
            public string Caption { get; set; }
        }
        public class MessageSticker<U,C> : EventArgs where U : User where C : Chat
        {
            public DefaultParameters<U,C> DefaultMessageInfo { get; set; }
            public DefaultMultiMediaMessageParameters DefaultMessageParameters { get; set;}
            public string Emoji { get; set; }
            
        }      
        public class MessageVideo<U, C> : EventArgs where U : User where C : Chat
        {
            public DefaultParameters<U, C> DefaultMessageInfo { get; set; }

            public DefaultMultiMediaMessageParameters DefaultMessageParameters { get; set; }

            public int Duration { get; set; }           
            public string Mime_type { get; set; }
           
        }
        public class MessageDocument<U, C> : EventArgs where U : User where C : Chat
        {
            public DefaultParameters<U, C> DefaultMessageInfo { get; set; }

            public string File_id { get; set; }
            public PhotoSize Thumb { get; set; }
            public string File_name { get; set; }
            public int File_size { get; set; }
            public string Mime_type { get; set; }
            
        }
        public class MessageLocation<U, C> : EventArgs where U : User where C : Chat
        {
            public DefaultParameters<U, C> DefaultMessageInfo { get; set; }
            public float Longitude { get; set; }
            public float Latitude { get; set; }
        }
        public class MessageContact<U, C> : EventArgs where U : User where C : Chat
        {
            public DefaultParameters<U,C> DefaultMessageInfo { get; set; }
            public string Phone_number { get; set; }
            public string First_name { get; set; }
            public string Last_name { get; set; }
            public int User_id { get; set; }
        }
        public class MessageVoice<U, C> : EventArgs where U : User where C : Chat
        {
            public DefaultParameters<U, C> DefaultMessageInfo { get; set; }
            public string File_id { get; set; }
            public int Duration { get; set; }
            public string Mime_type { get; set; }
            public int File_size { get; set; }
        }
        #endregion
    }
}
