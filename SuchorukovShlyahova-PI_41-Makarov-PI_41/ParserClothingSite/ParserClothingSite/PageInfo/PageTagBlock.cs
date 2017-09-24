using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParserClothingSite.PageInfo
{
    public class PageTagBlock : PageSimpleBlock
    {
        #region PRivate member
        private Dictionary<string, string> Attributes;
        #endregion
        #region Constructor
        public PageTagBlock(string _type, string _value, Dictionary<string, string> _dictionary) : base(_type, _value)
        {
            Contract.Requires(_dictionary != null);
            if (Attributes == null)
                Attributes = new Dictionary<string, string>();
            foreach (KeyValuePair<string, string> pair in _dictionary)
            {
                Attributes.Add(pair.Key, pair.Value);
            }
        } 
      
        public PageTagBlock(string _type, string _value) : base(_type, _value)
        {
            Attributes = new Dictionary<string, string>();
        }
        #endregion
        #region Public methods
        public void AddAttribute(string _key, string _value)
        {
            Func<bool> requires = () =>
            {
                return (string.IsNullOrEmpty(_key as string) || string.IsNullOrEmpty(_value as string));
            };
            Contract.Requires(Attributes != null);
            Contract.Requires(!requires(), "Key or value is null or empty");
            Attributes.Add(_key, _value);
        }
        public IEnumerable<KeyValuePair<string, string>> GetAttributeFilterCollection(Func<KeyValuePair<string, string>, bool> _predicate)
        {
            IEnumerable<KeyValuePair<string, string>> result = Attributes.Where(el => _predicate(el));
            return result;
        }
        public string GetAttribute(string _key)
        {
            Attributes.TryGetValue(_key, out string output);
            return output;
        }
        //public override Type GetTypeBlock()
        //{
        //    Func<bool> requires = () =>
        //    {
        //        return (string.IsNullOrEmpty(this.TypeBlock) || this.Value == null);
        //    };
        //    Contract.Requires(!requires(), "this element does not exist");
        //    return base.GetType();
        //}
        public override object Clone()
        {
            return new PageTagBlock(this.TypeBlock, this.Value, this.Attributes);
        } 
        #endregion
    }
}
