using System;


namespace ParserClothingSite.PageInfo
{
    public abstract class PageSimpleBlock : ICloneable
    {
        #region Protected members
        protected string TypeBlock { get; private set; }
        protected string Value { get; private set; }
        #endregion
        #region Constructor
        public PageSimpleBlock(string _type, string _value)
        {
            TypeBlock = _type;
            Value = _value;
        }
        #endregion
        #region Public methods
        //public virtual Type GetTypeBlock()
        //{
        //    return typeof(T);
        //}
        public virtual object Clone()
        {
            throw new NotImplementedException();
        }
        #endregion
    }
}
