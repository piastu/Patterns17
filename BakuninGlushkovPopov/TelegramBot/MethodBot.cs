using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace TelegramBot
{
    class MethodBot
    {
        string Token;
        string LINK = "https://api.telegram.org/bot";
        public MethodBot(string _token)
        {
            Token = _token;
        }
        public string Getme()
        {
            using (WebClient webClient = new WebClient())
            {
                string response = webClient.DownloadString(LINK + Token + "/getMe");
                return response;
            }
        }

        public void SendMessage(string _message, int _chatID)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "text", _message }
                };
                webClient.UploadValues(LINK + Token + "/sendMessage", pars);
            }
        }

        public void ForwardMessage(int _fromChatID, int _chatId, int _messageID)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatId.ToString() },
                    { "from_chat_id", _fromChatID.ToString() },
                    { "message_id", _messageID.ToString() }
                };
                webClient.UploadValues(LINK + Token + "/forwardMessage", pars);
            }
        }

        async public Task SendPhotoIputFile(int _chatID, string _pathToPhoto, string _catprion = "")
        {
            using (MultipartFormDataContent form = new MultipartFormDataContent())
            {
                string url = LINK + Token + "/sendPhoto";
                string fileName = _pathToPhoto.Split('\\').Last();

                form.Add(new StringContent(_chatID.ToString(), Encoding.UTF8), "chat_id");
                form.Add(new StringContent(_catprion.ToString(), Encoding.UTF8), "caption");
               
                using (FileStream fileStream = new FileStream(_pathToPhoto, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "photo", fileName);
                    using (HttpClient client = new HttpClient())
                        await client.PostAsync(url, form);
                }
            }

        }
        public void SendPhotoLink(int _chatID, string _linkToPhoto, string _caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "photo", _linkToPhoto },
                    { "caption", _caption }
                };
                webClient.UploadValues(LINK + Token + "/sendPhoto", pars);
            }
        }

         public async Task SendAudioIputFile(int _chatID, string _pathToAudio, string _catprion = "", int _duration = 0,
            string _performer = "", string _title = "")
        {
            using (MultipartFormDataContent form = new MultipartFormDataContent())
            {
                string url = LINK + Token + "/sendAudio";
                string fileName = _pathToAudio.Split('\\').Last();

                form.Add(new StringContent(_chatID.ToString(), Encoding.UTF8), "chat_id");
                form.Add(new StringContent(_catprion.ToString(), Encoding.UTF8), "caption");
                form.Add(new StringContent(_duration.ToString(), Encoding.UTF8), "duration");
                form.Add(new StringContent(_performer.ToString(), Encoding.UTF8), "performer");
                form.Add(new StringContent(_title.ToString(), Encoding.UTF8), "title");
                using (FileStream fileStream = new FileStream(_pathToAudio, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "audio", fileName);
                    using (HttpClient client = new HttpClient())
                        await client.PostAsync(url, form);
                }
            }

        }
        public void SendAudioLink(int _chatID, string _linkToAudio, string _caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "audio", _linkToAudio },
                    { "caption", _caption }
                };
                webClient.UploadValues(LINK + Token + "/sendAudio", pars);
            }
        }

        public async Task SendDocumentIputFile(int _chatID, string _pathToDocument, string _catprion = "")
        {
            using (MultipartFormDataContent form = new MultipartFormDataContent())
            {
                string url = LINK + Token + "/sendDocument";
                string fileName = _pathToDocument.Split('\\').Last();

                form.Add(new StringContent(_chatID.ToString(), Encoding.UTF8), "chat_id");
                form.Add(new StringContent(_catprion.ToString(), Encoding.UTF8), "caption");
                using (FileStream fileStream = new FileStream(_pathToDocument, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "document", fileName);
                    using (HttpClient client = new HttpClient())
                        await client.PostAsync(url, form);
                }
            }

        }
        public void SendDocumentoLink(int _chatID, string _linkToDocument, string _caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "document", _linkToDocument },
                    { "caption", _caption }
                };
                webClient.UploadValues(LINK + Token + "/sendDocument", pars);
            }
        }

        public void SendSticker(int _chatID, string _idSticker)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "sticker", _idSticker }
                };
                webClient.UploadValues("https://api.telegram.org/bot" + Token + "/sendSticker", pars);
            }
        }

        public async Task SendVideoInputFile(int _chatID, string _pathToVideo, string _caption = "")
        {
            using (var form = new MultipartFormDataContent())
            {
                string url = string.Format("https://api.telegram.org/bot{0}/sendVideo", Token);
                string fileName = _pathToVideo.Split('\\').Last();

                form.Add(new StringContent(_chatID.ToString(), Encoding.UTF8), "chat_id");
                form.Add(new StringContent(_caption, Encoding.UTF8), "caption");

                using (FileStream fileStream = new FileStream(_pathToVideo, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "video", fileName);
                    using (var client = new HttpClient())
                    {
                        await client.PostAsync(url, form);
                    }
                }
            }
        }
        public void SendVideoLink(int _chatID, string _linkToVideo, string _caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "video", _linkToVideo },
                    { "caption", _caption }
                };
                webClient.UploadValues("https://api.telegram.org/bot" + Token + "/sendVideo", pars);
            }
        }

        public async Task SendVoiceInputFile(int _chatID, string _pathToVoice, string _caption = "", int _duration = 0)
        {
            using (MultipartFormDataContent form = new MultipartFormDataContent())
            {
                string url = "https://api.telegram.org/bot" + Token + "/sendVoice";
                string fileName = _pathToVoice.Split('\\').Last();

                form.Add(new StringContent(_chatID.ToString(), Encoding.UTF8), "chat_id");
                using (FileStream fileStream = new FileStream(_pathToVoice, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "voice", fileName);
                    form.Add(new StringContent(_caption, Encoding.UTF8), "caption");
                    form.Add(new StringContent(_duration.ToString(), Encoding.UTF8), "duration");
                    using (HttpClient client = new HttpClient())
                    {
                        await client.PostAsync(url, form);
                    }
                }
            }
        }
        public void SendVoiceLink(int _chatID, string _linkToAudio, string _caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "voice", _linkToAudio },
                    { "caption", _caption }
                };
                webClient.UploadValues("https://api.telegram.org/bot" + Token + "/sendVoice", pars);
            }
        }

        public void SendLocation(int _chatID, float _latitude, float _longitude)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "latitude", _latitude.ToString() },
                    { "longitude", _longitude.ToString() }
                };
                webClient.UploadValues("https://api.telegram.org/bot" + Token + "/SendLocation", pars);
            }
        }

        

        public void SendVenue(int _chatID, float _latitude, float _longitude, string _title, 
            string _address, string _foursquareId = "1")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "latitude", _latitude.ToString() },
                    { "longitude", _longitude.ToString() },
                    { "title", _title },
                    { "address", _address },
                    { "foursquare_id", _foursquareId }
                };
                webClient.UploadValues("https://api.telegram.org/bot" + Token + "/SendVenue", pars);
            }
        }

        public void SendContact(int _chatID, string _phoneNumber, string _firstName, string _lastName)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "phone_number", _phoneNumber },
                    { "first_name", _firstName },
                    { "last_name", _lastName }
                };
                webClient.UploadValues("https://api.telegram.org/bot" + Token + "/SendContact", pars);
            }
        }

        public void SendChatAction(int _chatID, ChatAction _action)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection
                {
                    { "chat_id", _chatID.ToString() },
                    { "action", _action.ToString() }
                };
                webClient.UploadValues("https://api.telegram.org/bot" + Token + "/sendChatAction", pars);
            }
        }
        public enum ChatAction
        {
            typing,
            upload_photo,
            record_video,
            upload_video,
            record_audio,
            upload_audio,
            upload_document,
            find_location
        }

        public string GetUserProfilePhotos(int _userId, int _offset, int _limit = 100)
        {
            using (WebClient webClient = new WebClient())
            {
                string response = webClient.DownloadString(LINK + Token + "/getUserProfilePhotos?user_id=" +
                    _userId + "&limit=" + _limit + "&offset=" + _offset);
                JSONNode N = JSON.Parse(response);
                N = N["result"]["photos"].AsArray[0];
                string linkPhoto = N[N.Count - 1]["file_id"];
                return linkPhoto;
            }
        }

        public string[] GetUserProfilePhotosAllTime(int _userId, int _offset, int _limit = 100)
        {
            using (WebClient webClient = new WebClient())
            {
                string response = webClient.DownloadString(LINK + Token + "/getUserProfilePhotos?user_id=" + 
                    _userId + "&limit=" + _limit + "&offset=" + _offset);
                JSONNode N = JSON.Parse(response);
                string[] linkPhoto = new string[N["result"]["total_count"].AsInt];
                int k = 0;
                foreach (JSONNode r in N["result"]["photos"].AsArray)
                {
                    linkPhoto[k] = r[r.Count - 1]["file_id"];
                    k++;
                }
                return linkPhoto;
            }
        }

        public string GetFile(string _fileId)
        {
            using (WebClient webClient = new WebClient())
            {
                string response = webClient.DownloadString(LINK + Token + "/getFile?file_id=" + _fileId);
                JSONNode N = JSON.Parse(response);
                response = "https://api.telegram.org/file/bot" + Token + "/" + N["result"]["file_path"];
                return response;
            }
        }
    }
}
