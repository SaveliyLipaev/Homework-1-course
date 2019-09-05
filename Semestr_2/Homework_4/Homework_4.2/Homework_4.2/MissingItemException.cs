using System;

namespace Homework_4._2
{
    /// <summary>
    /// исключение генерируещееся если элемента в контейнере не найдено
    /// </summary>
    public class MissingItemException : Exception
    {
        public MissingItemException()
        { }

        public MissingItemException(string message)
            : base(message)
        { }
    }
}
