using System;
using System.Net;
using TelegramBot.EventTypes.EventFactory;
using TelegramBot.TelegramSubject;
using static TelegramBot.EventTypes.EventType;

namespace TelegramBot
{
    #region Делгаты
    public delegate void ResponseText(object sendr, MessageText<User, Chat> e);
    public delegate void ResponseSticker(object sendr, MessageSticker<User, Chat> e);
    public delegate void ResponsePhoto(object sendr, MessagePhoto<User, Chat> e);
    public delegate void ResponseVideo(object sendr, MessageVideo<User, Chat> e);
    public delegate void ResponseDocument(object sendr, MessageDocument<User, Chat> e);
    public delegate void ResponseLocation(object sendr, MessageLocation<User, Chat> e);
    public delegate void ResponseContact(object sendr, MessageContact<User, Chat> e);
    public delegate void ResponseVoice(object sendr, MessageVoice<User, Chat> e);
    #endregion

    public class TelegramRequest
    {
        public StandartEventFactor Factory = new StandartEventFactor();
        public string _token;
        public TelegramRequest(string Token)
        {
            _token = Token;
        }
        int LastUpdateID = 0;
        #region Events
        public event ResponseText MessageText;
        public event ResponseSticker MessageSticker;
        public event ResponsePhoto MessagePhoto;
        public event ResponseVideo MessageVideo;
        public event ResponseDocument MessageDocument;
        public event ResponseLocation MessageLocation;
        public event ResponseContact MessageContact;
        public event ResponseVoice MessageVoice; 
        #endregion
        public void GetUpdates()
        {
            while (true)
            {
                using (WebClient webClient = new WebClient())
                {
                    string response = webClient.DownloadString("https://api.telegram.org/bot" + _token + "/getupdates?offset=" + (LastUpdateID + 1));
                    if (response.Length <= 23)
                        continue;
                    var N = JSON.Parse(response);
                    foreach (JSONNode r in N["result"].AsArray)
                    {
                        string _type = r["message"].ToString();
                        _type = WhatsType(_type).Replace("\"", "");
                        LastUpdateID = r["update_id"].AsInt;
                        #region SWITCH
                        switch (_type)
                        {
                            case "text":
                                {
                                    try
                                    {
                                        MessageText.Method.Name.ToString();
                                        Notification();
                                        Console.WriteLine("Мы получили текстовое сообщение");
                                        Notification(false);
                                    }
                                    catch (Exception)
                                    { break; }
                                    GetMessageText(r);
                                    break;
                                }
                            case "sticker":
                                {
                                    try
                                    {
                                        MessageText.Method.Name.ToString();
                                        Notification();
                                        Console.WriteLine("Мы получили cтикер");
                                        Notification(false);
                                    }
                                    catch (Exception)
                                    { break; }
                                    GetMessageSticker(r);
                                    break;
                                }
                            case "photo":
                                {
                                    try
                                    {
                                        MessageText.Method.Name.ToString();
                                        Notification();
                                        Console.WriteLine("Мы получили фотографию");
                                        Notification(false);
                                    }
                                    catch (Exception)
                                    { break; }
                                    GetMessagePhoto(r);
                                    break;
                                }
                            case "video":
                                {
                                    try
                                    {
                                        MessageText.Method.Name.ToString();
                                        Notification();
                                        Console.WriteLine("Мы получили видеозапись");
                                        Notification(false);
                                    }
                                    catch (Exception)
                                    { break; }
                                    GetMessageVideo(r);
                                    break;
                                }
                            case "document":
                                {
                                    try
                                    {
                                        MessageText.Method.Name.ToString();
                                        Notification();
                                        Console.WriteLine("Мы получили документ");
                                        Notification(false);
                                    }
                                    catch (Exception)
                                    { break; }
                                    GetMessageDocument(r);
                                    break;
                                }
                            case "location":
                                {
                                    try
                                    {
                                        MessageText.Method.Name.ToString();
                                        Notification();
                                        Console.WriteLine("Мы получили локацию");
                                        Notification(false);
                                    }
                                    catch (Exception)
                                    { break; }
                                    GetMessageLocation(r);
                                    break;
                                }
                            case "contact":
                                {
                                    try
                                    {
                                        MessageText.Method.Name.ToString();
                                        Notification();
                                        Console.WriteLine("Мы получили контакт");
                                        Notification(false);
                                    }
                                    catch (Exception)
                                    { break; }
                                    GetMessageContact(r);
                                    break;
                                }
                            case "voice":
                                {
                                    try
                                    {
                                        MessageText.Method.Name.ToString();
                                        Notification();
                                        Console.WriteLine("Мы получили голосовую запись");
                                        Notification(false);
                                    }
                                    catch (Exception)
                                    { break; }
                                    GetMessageVoice(r);
                                    break;
                                }
                        }
                        #endregion
                    }
                }
            }
        }
        private string WhatsType(string JSON)
        {
            string[] Type = { "text", "sticker", "photo", "video", "document", "location", "contact", "voice" };
            for (int i = 0; i < Type.Length; i++)
            {
                try { JSON = JSON.Remove(0, JSON.LastIndexOf("\"" + Type[i] + "\"")); }
                catch (Exception) { continue; }
                JSON = JSON.Remove(JSON.IndexOf(":"));
                break;
            }
            return JSON;
        }
        private void Notification(bool on = true)
        {
            if (on)
            {
                Console.BackgroundColor = ConsoleColor.Yellow;
                Console.ForegroundColor = ConsoleColor.Black;
            }
            else
            {
                Console.BackgroundColor = ConsoleColor.Black;
                Console.ForegroundColor = ConsoleColor.White;
            }
        }
        #region Method
        private void GetMessageText(JSONNode answer)
        {
            var message = Factory.CreateMessageTextEvent(answer);
            MessageText(this, message );
        }
        private void GetMessageSticker(JSONNode answer)
        {         
            var message = Factory.CreateMessageStickerEvent(answer);
            MessageSticker(this, message);
        }
        private void GetMessagePhoto(JSONNode answer)
        {           
            var message = Factory.CreateMessagePhotoEvent(answer);
            MessagePhoto(this, message);
        }
        private void GetMessageVideo(JSONNode answer)
        {
            var message = Factory.CreateMessageVideoEvent(answer);
            MessageVideo(this, message);
        }
        private void GetMessageDocument(JSONNode answer)
        {
            var message = Factory.CreateMessageDocumentEvent(answer);
            MessageDocument(this, message);
        }
        private void GetMessageLocation(JSONNode answer)
        {

            var message = Factory.CreateMessageLocationEvent(answer);
            MessageLocation(this, message);
        }
        private void GetMessageContact(JSONNode answer)
        {
            var message = Factory.CreateMessageContactEvent(answer);
            MessageContact(this, message);
        }
        private void GetMessageVoice(JSONNode answer)
        {

            var message = Factory.CreateMessageVoiceEvent(answer);
            MessageVoice(this, message);
        }
        #endregion
    }

}
