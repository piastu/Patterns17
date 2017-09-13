using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TelegramBot.TelegramSubject;
using static TelegramBot.EventTypes.EventType;

namespace TelegramBot.EventTypes.EventFactory
{
    public class StandartEventFactor : AbstractEventFactory
    {
        

    private string GetEmoji(JSONNode _node) => _node["message"]["sticker"]["height"];
        private string GetTextMessage(JSONNode _node) => _node["message"]["text"];
        private string GetCaption(JSONNode _node) => _node["message"]["caption"];
        #region VideoHelper
        private int GetVideoDuration(JSONNode _node) => _node["message"]["video"]["duration"].AsInt;
        private string GetVideoMimeType(JSONNode _node) => _node["message"]["video"]["mime_type"];
        private float GetLongitude(JSONNode _node) => _node["message"]["location"]["longitude"].AsFloat;
        private float GetLatitude(JSONNode _node) => _node["message"]["location"]["latitude"].AsFloat;
        #endregion
        #region ContactHelper
        private string GetPhoneNumber(JSONNode _node) => _node["message"]["contact"]["phone_number"];
        private string GetFirstName(JSONNode _node) => _node["message"]["contact"]["first_name"];
        private string GetLastName(JSONNode _node) => _node["message"]["contact"]["last_name"];
        private int GetUserId(JSONNode _node) => _node["message"]["contact"]["user_id"].AsInt;
        #endregion
        #region VoiceHelper
        private int GetVoiceFileSize(JSONNode _node) => _node["message"]["voice"]["file_size"].AsInt;
        private int GetVoiceDuration(JSONNode _node) => _node["message"]["voice"]["duration"].AsInt;
        private string GetVoiceFileId(JSONNode _node) => _node["message"]["voice"]["file_id"];
        private string GetVoiceMimeType(JSONNode _node) => _node["message"]["voice"]["mime_type"];
        #endregion
        #region DocumentHelper
        private string GetDocumentMimeType(JSONNode _node) => _node["message"]["document"]["mime_type"];
        private string GetDocumentFileId(JSONNode _node) => _node["message"]["document"]["file_id"];
        private string GetDocumentFileName(JSONNode _node) => _node["message"]["document"]["file_name"];
        private int GetDocumentFileSize(JSONNode _node) => _node["message"]["document"]["file_size"].AsInt;
        #endregion
        #region PrivateMembers
        /// <summary>
        /// id message user info, chat info, date receiver
        /// </summary>
        private DefaultInformation defaultInformation;
        #endregion
        #region Constructor
        public StandartEventFactor()
        {
            defaultInformation = new DefaultInformation();
        }
        #endregion
        

    private List<PhotoSize> GetPhotoSizeCollection(JSONNode _node)
        {
            List<PhotoSize> _temp = new List<PhotoSize>();
            for (int i = 0; i < _node["message"]["photo"].Count; i++)
            {
                _temp.Add(new PhotoSize
                {
                    File_id = _node["message"]["photo"][i]["file_id"],
                    File_size = _node["message"]["photo"][i]["file_size"].AsInt,
                    Height = _node["message"]["photo"][i]["height"].AsInt,
                    Width = _node["message"]["photo"][i]["width"].AsInt
                });
            }
            return _temp;
        }

        private PhotoSize GetThumb(JSONNode _node, string type)
        {
            return new PhotoSize()
            {
                File_id = _node["message"][type]["thumb"]["file_id"],
                File_size = _node["message"][type]["thumb"]["file_size"].AsInt,
                Width = _node["message"][type]["thumb"]["width"].AsInt,
                Height = _node["message"][type]["thumb"]["height"].AsInt
            };
        }

        private DefaultMultiMediaMessageParameters GetMultiMediaMessageParameters(JSONNode _node, string type)
        {
            return new DefaultMultiMediaMessageParameters()
            {
                Width = _node["message"][type]["width"].AsInt,
                Height = _node["message"][type]["height"].AsInt,
                File_id = _node["message"][type]["file_id"],
                File_size = _node["message"][type]["file_size"].AsInt,
            };
        }

        public override MessageSticker<User, Chat> CreateMessageStickerEvent(JSONNode _node)
        {
            defaultInformation.Node = _node;
            var _defaultparams = GetMultiMediaMessageParameters(_node, "sticker");
            _defaultparams.Thumb = GetThumb(_node, "sticker");

            return new MessageSticker<User, Chat>()
            {
                DefaultMessageInfo = defaultInformation.GetDefaultParameters(),               
                DefaultMessageParameters = _defaultparams,
                Emoji = GetEmoji(_node)
            };

        }
        public override EventType.MessageText<User, Chat> CreateMessageTextEvent(JSONNode _node)
        {
            defaultInformation.Node = _node;
            return new MessageText<User, Chat>()
            {
                DefaultMessageInfo = defaultInformation.GetDefaultParameters(),
                Text = GetTextMessage(_node)
            };
        }

        public override MessagePhoto<User, Chat> CreateMessagePhotoEvent(JSONNode _node)
        {
            defaultInformation.Node = _node;
            List<PhotoSize> _photoCollection = GetPhotoSizeCollection(_node);
            return new MessagePhoto<User, Chat>()
            {
                DefaultMessageInfo = defaultInformation.GetDefaultParameters(),
                PhotoCollection = _photoCollection,
                Caption = GetCaption(_node),
            };
        }



        public override MessageVideo<User, Chat> CreateMessageVideoEvent(JSONNode _node)
        {

            defaultInformation.Node = _node;
            var _defaultparams = GetMultiMediaMessageParameters(_node, "video");
            _defaultparams.Thumb = GetThumb(_node, "video");

            return new MessageVideo<User, Chat>()
            {
                DefaultMessageInfo = defaultInformation.GetDefaultParameters(),
                DefaultMessageParameters = _defaultparams,
                Duration = GetVideoDuration(_node),
                Mime_type = GetVideoMimeType(_node),
            };

        }
        public override MessageDocument<User, Chat> CreateMessageDocumentEvent(JSONNode _node)
        {
            defaultInformation.Node = _node;
            PhotoSize _thumb = GetThumb(_node, "document");
            return new MessageDocument<User, Chat>()
            {
                DefaultMessageInfo = defaultInformation.GetDefaultParameters(),
                Thumb = _thumb,
                Mime_type = GetDocumentMimeType(_node),
                File_id = GetDocumentFileId(_node),
                File_name = GetDocumentFileName(_node),
                File_size = GetDocumentFileSize(_node), 
            };
        }

        public override MessageLocation<User, Chat> CreateMessageLocationEvent(JSONNode _node)
        {
            defaultInformation.Node = _node;
            return new MessageLocation<User, Chat>()
            {
                DefaultMessageInfo = defaultInformation.GetDefaultParameters(),
                Longitude = GetLongitude(_node),
                Latitude = GetLatitude(_node),
            };
        }

        public override MessageContact<User, Chat> CreateMessageContactEvent(JSONNode _node)
        {
            defaultInformation.Node = _node;
            return new MessageContact<User, Chat>()
            {
                DefaultMessageInfo = defaultInformation.GetDefaultParameters(),
                Phone_number = GetPhoneNumber(_node),
                First_name = GetFirstName(_node),
                Last_name = GetLastName(_node),
                User_id = GetUserId(_node),
            };
        }

        public override MessageVoice<User, Chat> CreateMessageVoiceEvent(JSONNode _node)
        {
            defaultInformation.Node = _node;
            return new MessageVoice<User, Chat>()
            {
                DefaultMessageInfo = defaultInformation.GetDefaultParameters(),
                File_size = GetVoiceFileSize(_node),
                File_id = GetVoiceFileId(_node),
                Duration = GetVoiceDuration(_node),
                Mime_type = GetVoiceMimeType(_node),
            };
        }
       
        public class DefaultInformation
        {
            public User User => GetUser();
            public Chat Chat => GetChat();
            public DateTime UTCDate => GetUTCDate();
            public int MessageId => GetMessageId();
            
            public JSONNode Node { get; set; }

            private User GetUser()
            {                
                return new User()
                {
                    Id = Node["message"]["from"]["id"].AsInt,
                    First_name = Node["message"]["from"]["first_name"],
                    Last_name = Node["message"]["from"]["last_name"],
                    Username = Node["message"]["from"]["username"]
                };
            }
            private Chat GetChat()
            {
                return new Chat()
                {
                    Id = Node["message"]["chat"]["id"].AsInt,
                    First_name = Node["message"]["chat"]["first_name"],
                    Last_name = Node["message"]["chat"]["last_name"],
                    Username = Node["message"]["chat"]["username"],
                    Type = Node["message"]["chat"]["type"],
                    Title = Node["message"]["chat"]["title"]
                };
            }
            private DateTime GetUTCDate()
            {
                return new DateTime(1970, 1, 1).AddSeconds(Node["message"]["date"].AsInt + 7 * 60 * 60);
            }
            private int GetMessageId()
            {
                return Node["message"]["message_id"].AsInt;
            }
            
            public DefaultParameters<User, Chat> GetDefaultParameters()
            {
                return new DefaultParameters<User, Chat>()
                {
                    MessageId = MessageId,
                    From = User,
                    Chat = Chat,
                    DateReveiver = UTCDate,
                };
            }

        }
    }
}
