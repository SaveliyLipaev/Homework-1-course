using System;

namespace Test_1
{
    /// <summary>
    /// Класс реализующий исключение, кидающееся если очередь пуста
    /// </summary>
     public class EmptyQueueException : Exception
    {
        public EmptyQueueException()
        { }

        public EmptyQueueException(string message)
            : base(message)
        { }
    }
}
