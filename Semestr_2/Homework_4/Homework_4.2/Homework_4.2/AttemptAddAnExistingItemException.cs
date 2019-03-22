using System;

namespace Homework_4._2
{
    public class AttemptAddAnExistingItemException : Exception
    {
        public AttemptAddAnExistingItemException()
        { }

        public AttemptAddAnExistingItemException(string message)
            : base(message)
        { }
    }
}
