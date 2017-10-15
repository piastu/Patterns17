using System;
using System.IO;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.GetContentHelper
{
    public class HtmlSubject : IGetHtmlContent
    {
        /// <summary>
        /// Get html content of page
        /// </summary>
        /// <param name="Url">Url page</param>
        /// <returns>html content or string as null</returns>
        public string GetContent(string url)
        {
           
            var httpWebRequest = (HttpWebRequest)WebRequest.Create(url);
            httpWebRequest.AllowAutoRedirect = false;//Запрещаем автоматический редирект
            httpWebRequest.Method = "GET"; //Можно не указывать, по умолчанию используется GET.
            httpWebRequest.Referer = "http://google.com"; // Реферер. Тут можно указать любой URL

            var httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
            Stream stream = null;
            try
            {
                stream = httpWebResponse.GetResponseStream();
                using (var reader = new StreamReader(stream, Encoding.GetEncoding(httpWebResponse.CharacterSet)))
                {
                    return reader.ReadToEnd();
                }
            }
            finally
            {
                if (stream != null)
                    stream.Dispose();
            }

        }
        /// <summary>
        /// Get html content of page
        /// </summary>
        /// <param name="Url">Url page</param>
        /// <returns></returns>
        public async Task<string> GetContentAsync(string url)
        {
            var httpMessage = new HttpClientHandler()
            {
                AllowAutoRedirect = false,
            };
            using (var client = new HttpClient(httpMessage))
            {
                return await client.GetStringAsync(url).ConfigureAwait(false);
            }
        }
    }
}
