using System;

namespace Homework_4._2
{
    /// <summary>
    /// Исключение вызывающиеся из-за попытки добавления существующего элемента
    /// </summary>
    public class AttemptAddAnExistingItemException : Exception
    {
        public AttemptAddAnExistingItemException()
        { }

        public AttemptAddAnExistingItemException(string message)
            : base(message)
        { }
    }
}
