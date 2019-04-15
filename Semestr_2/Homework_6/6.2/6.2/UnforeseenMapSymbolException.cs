using System;

namespace _6._2
{
    /// <summary>
    /// Исключение бросающееся если встретился символ о котром не знает игра
    /// </summary>
    [Serializable]
    public class UnforeseenMapSymbolException : Exception
    {
        public UnforeseenMapSymbolException()
        { }

        public UnforeseenMapSymbolException(string message)
            : base(message)
        { }
    }
}
