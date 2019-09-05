using System;

namespace _6._2
{
    /// <summary>
    /// Исключение бросающееся если на карте больше 1 героя
    /// </summary>
    [Serializable]
    public class TwoHeroOnMapException : Exception
    {
        public TwoHeroOnMapException()
        { }

        public TwoHeroOnMapException(string message)
            : base(message)
        { }
    }
}
