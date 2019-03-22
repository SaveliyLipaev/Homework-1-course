using System;

namespace Homework_4._2
{
    public class MissingItemException : Exception
    {
        public MissingItemException()
        { }

        public MissingItemException(string message)
            : base(message)
        { }
    }
}
