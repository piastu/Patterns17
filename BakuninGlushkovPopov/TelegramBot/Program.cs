using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using TelegramBot.TelegramSubject;
using static TelegramBot.EventTypes.EventType;

namespace TelegramBot
{
    class Program
    {
        static void Main(string[] args)
        {
            TelegramRequest Tr = new TelegramRequest(Settings.Default.Token);
            #region Events
            Tr.MessageText += Tr_MessageText;
            Tr.MessageSticker += Tr_MessageSticker;
            Tr.MessagePhoto += Tr_MessagePhoto;
            Tr.MessageVideo += Tr_MessageVideo;
            Tr.MessageDocument += Tr_MessageDocument;
            Tr.MessageLocation += Tr_MessageLocation;
            Tr.MessageContact += Tr_MessageContact;
            Tr.MessageVoice += Tr_MessageVoice; 
            #endregion


            Task taskcompleatemsg = new Task( ()=>Tr.GetUpdates());        
            taskcompleatemsg.Start();           
            MethodBot mb = new MethodBot(Settings.Default.Token);             
            Console.ReadKey();           
        }
     
        private static void Tr_MessageText(object sendr, MessageText<User, Chat> e)
        {
            
            Console.WriteLine("ID сообщения:{0}\nID отправителя:{1}\nНик отправителя:{2}\nИмя:{3} Фамилия:{4}\nДата:{5}\nТекст сообщения:{6}",
               e.DefaultMessageInfo.MessageId, e.DefaultMessageInfo.From.Id, e.DefaultMessageInfo.From.Username, 
               e.DefaultMessageInfo.From.First_name, e.DefaultMessageInfo.From.Last_name, 
               e.DefaultMessageInfo.DateReveiver, e.Text);
        }
        private static void Tr_MessageSticker(object sendr, MessageSticker<User, Chat> e)
        {
           
        }
        private static void Tr_MessagePhoto(object sendr, MessagePhoto<User, Chat> e)
        {
          
        }
        private static void Tr_MessageVideo(object sendr, MessageVideo<User, Chat> e)
        {
           
        }
        private static void Tr_MessageDocument(object sendr, MessageDocument<User, Chat> e)
        {
          
        }
        private static void Tr_MessageLocation(object sendr, MessageLocation<User, Chat> e)
        {
           
        }
        private static void Tr_MessageContact(object sendr, MessageContact<User, Chat> e)
        {
          
        }
        private static void Tr_MessageVoice(object sendr, MessageVoice<User, Chat> e)
        {
            
        }
    }
}
