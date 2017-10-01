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
        string _token;
        string LINK = "https://api.telegram.org/bot";
        public MethodBot(string Token)
        {
            _token = Token;
        }
        public string Getme()
        {
            using (WebClient webClient = new WebClient())
            {
                string response = webClient.DownloadString(LINK + _token + "/getMe");
                return response;
            }
        }

        public void SendMessage(string message, int ChatID)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", ChatID.ToString());
                pars.Add("text", message);
                webClient.UploadValues(LINK + _token + "/sendMessage", pars);
            }
        }

        public void ForwardMessage(int fromChatID, int chatId, int messageID)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", chatId.ToString());
                pars.Add("from_chat_id", fromChatID.ToString());
                pars.Add("message_id", messageID.ToString());
                webClient.UploadValues(LINK + _token + "/forwardMessage", pars);
            }
        }

        async public Task SendPhotoIputFile(int ChatID, string pathToPhoto, string catprion = "")
        {
            using (MultipartFormDataContent form = new MultipartFormDataContent())
            {
                string url = LINK + _token + "/sendPhoto";
                string fileName = pathToPhoto.Split('\\').Last();

                form.Add(new StringContent(ChatID.ToString(), Encoding.UTF8), "chat_id");
                form.Add(new StringContent(catprion.ToString(), Encoding.UTF8), "caption");
               
                using (FileStream fileStream = new FileStream(pathToPhoto, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "photo", fileName);
                    using (HttpClient client = new HttpClient())
                        await client.PostAsync(url, form);
                }
            }

        }
        public void SendPhotoLink(int ChatID, string linkToPhoto, string caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", ChatID.ToString());
                pars.Add("photo", linkToPhoto);
                pars.Add("caption", caption);
                webClient.UploadValues(LINK + _token + "/sendPhoto", pars);
            }
        }

        async public Task SendAudioIputFile(int ChatID, string pathToAudio, string catprion = "", int duration = 0, string performer = "", string title = "")
        {
            using (MultipartFormDataContent form = new MultipartFormDataContent())
            {
                string url = LINK + _token + "/sendAudio";
                string fileName = pathToAudio.Split('\\').Last();

                form.Add(new StringContent(ChatID.ToString(), Encoding.UTF8), "chat_id");
                form.Add(new StringContent(catprion.ToString(), Encoding.UTF8), "caption");
                form.Add(new StringContent(duration.ToString(), Encoding.UTF8), "duration");
                form.Add(new StringContent(performer.ToString(), Encoding.UTF8), "performer");
                form.Add(new StringContent(title.ToString(), Encoding.UTF8), "title");
                using (FileStream fileStream = new FileStream(pathToAudio, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "audio", fileName);
                    using (HttpClient client = new HttpClient())
                        await client.PostAsync(url, form);
                }
            }

        }
        public void SendAudioLink(int ChatID, string linkToAudio, string caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", ChatID.ToString());
                pars.Add("audio", linkToAudio);
                pars.Add("caption", caption);
                webClient.UploadValues(LINK + _token + "/sendAudio", pars);
            }
        }

        async public Task SendDocumentIputFile(int ChatID, string pathToDocument, string catprion = "")
        {
            using (MultipartFormDataContent form = new MultipartFormDataContent())
            {
                string url = LINK + _token + "/sendDocument";
                string fileName = pathToDocument.Split('\\').Last();

                form.Add(new StringContent(ChatID.ToString(), Encoding.UTF8), "chat_id");
                form.Add(new StringContent(catprion.ToString(), Encoding.UTF8), "caption");
                using (FileStream fileStream = new FileStream(pathToDocument, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "document", fileName);
                    using (HttpClient client = new HttpClient())
                        await client.PostAsync(url, form);
                }
            }

        }
        public void SendDocumentoLink(int ChatID, string linkToDocument, string caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", ChatID.ToString());
                pars.Add("document", linkToDocument);
                pars.Add("caption", caption);
                webClient.UploadValues(LINK + _token + "/sendDocument", pars);
            }
        }

        public void SendSticker(int chatID, string IDsticker)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", chatID.ToString());
                pars.Add("sticker", IDsticker);
                webClient.UploadValues("https://api.telegram.org/bot" + _token + "/sendSticker", pars);
            }
        }

        async public Task SendVideoInputFile(int chatID, string pathToVideo, string caption = "")
        {
            using (var form = new MultipartFormDataContent())
            {
                string url = string.Format("https://api.telegram.org/bot{0}/sendVideo", _token);
                string fileName = pathToVideo.Split('\\').Last();

                form.Add(new StringContent(chatID.ToString(), Encoding.UTF8), "chat_id");
                form.Add(new StringContent(caption, Encoding.UTF8), "caption");

                using (FileStream fileStream = new FileStream(pathToVideo, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "video", fileName);
                    using (var client = new HttpClient())
                    {
                        await client.PostAsync(url, form);
                    }
                }
            }
        }
        public void SendVideoLink(int chatID, string linkToVideo, string caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", chatID.ToString());
                pars.Add("video", linkToVideo);
                pars.Add("caption", caption);
                webClient.UploadValues("https://api.telegram.org/bot" + _token + "/sendVideo", pars);
            }
        }

        async public Task SendVoiceInputFile(int chatID, string pathToVoice, string caption = "", int duration = 0)
        {
            using (MultipartFormDataContent form = new MultipartFormDataContent())
            {
                string url = "https://api.telegram.org/bot" + _token + "/sendVoice";
                string fileName = pathToVoice.Split('\\').Last();

                form.Add(new StringContent(chatID.ToString(), Encoding.UTF8), "chat_id");
                using (FileStream fileStream = new FileStream(pathToVoice, FileMode.Open, FileAccess.Read))
                {
                    form.Add(new StreamContent(fileStream), "voice", fileName);
                    form.Add(new StringContent(caption, Encoding.UTF8), "caption");
                    form.Add(new StringContent(duration.ToString(), Encoding.UTF8), "duration");
                    using (HttpClient client = new HttpClient())
                    {
                        await client.PostAsync(url, form);
                    }
                }
            }
        }
        public void SendVoiceLink(int chatID, string linkToAudio, string caption = "")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", chatID.ToString());
                pars.Add("voice", linkToAudio);
                pars.Add("caption", caption);
                webClient.UploadValues("https://api.telegram.org/bot" + _token + "/sendVoice", pars);
            }
        }

        public void SendLocation(int chatID, float latitude, float longitude)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", chatID.ToString());
                pars.Add("latitude", latitude.ToString());
                pars.Add("longitude", longitude.ToString());
                webClient.UploadValues("https://api.telegram.org/bot" + _token + "/SendLocation", pars);
            }
        }

        public void SendVenue(int chatID, float latitude, float longitude, string title, string address, string foursquare_id = "1")
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", chatID.ToString());
                pars.Add("latitude", latitude.ToString());
                pars.Add("longitude", longitude.ToString());
                pars.Add("title", title);
                pars.Add("address", address);
                pars.Add("foursquare_id", foursquare_id);
                webClient.UploadValues("https://api.telegram.org/bot" + _token + "/SendVenue", pars);
            }
        }

        public void SendContact(int chatID, string phone_number, string first_name, string last_name)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", chatID.ToString());
                pars.Add("phone_number", phone_number);
                pars.Add("first_name", first_name);
                pars.Add("last_name", last_name);
                webClient.UploadValues("https://api.telegram.org/bot" + _token + "/SendContact", pars);
            }
        }

        public void SendChatAction(int chatID, ChatAction action)
        {
            using (WebClient webClient = new WebClient())
            {
                NameValueCollection pars = new NameValueCollection();
                pars.Add("chat_id", chatID.ToString());
                pars.Add("action", action.ToString());
                webClient.UploadValues("https://api.telegram.org/bot" + _token + "/sendChatAction", pars);
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

        public string getUserProfilePhotos(int user_id, int offset, int limit = 100)
        {
            using (WebClient webClient = new WebClient())
            {
                string response = webClient.DownloadString(LINK + _token + "/getUserProfilePhotos?user_id=" + user_id + "&limit=" + limit + "&offset=" + offset);
                JSONNode N = JSON.Parse(response);
                N = N["result"]["photos"].AsArray[0];
                string linkPhoto = N[N.Count - 1]["file_id"];
                return linkPhoto;
            }
        }

        public string[] getUserProfilePhotosAllTime(int user_id, int offset, int limit = 100)
        {
            using (WebClient webClient = new WebClient())
            {
                string response = webClient.DownloadString(LINK + _token + "/getUserProfilePhotos?user_id=" + user_id + "&limit=" + limit + "&offset=" + offset);
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

        public string getFile(string file_id)
        {
            using (WebClient webClient = new WebClient())
            {
                string response = webClient.DownloadString(LINK + _token + "/getFile?file_id=" + file_id);
                JSONNode N = JSON.Parse(response);
                response = "https://api.telegram.org/file/bot" + _token + "/" + N["result"]["file_path"];
                return response;
            }
        }
    }
}
