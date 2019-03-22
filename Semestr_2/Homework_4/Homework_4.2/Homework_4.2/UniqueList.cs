using System;

namespace Homework_4._2
{
    public class UniqueList : List
    {
        private bool FindNode(int data)
        {
            var ptr = head;
            while(ptr != null)
            {
                if (ptr.data == data) 
                {
                    return true;
                }
                ptr = ptr.next;
            }
            return false;
        }

        public override void Add(int data)
        {
            if (FindNode(data))
            {
                throw new AttemptAddAnExistingItemException("Невозможно добавить элемент в список, он уже существует");
            }

            base.Add(data);
        }
    }
}
