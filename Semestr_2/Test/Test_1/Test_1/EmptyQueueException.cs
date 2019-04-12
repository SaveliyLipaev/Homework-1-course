using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
