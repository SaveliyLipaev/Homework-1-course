using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace List
{
    class MyList<T> : IList<T>
    {
        private Node head;
        private Node tail;

        public int Count { get; private set; }

        public T this[int index] { get => TakeNodeIndex(index).Data; set => TakeNodeIndex(index).Data = this[index]; }

        public bool IsReadOnly => false;

        private class Node
        {
            public Node Next { get; set; }
            public T Data { get; set; }

            public Node(Node next, T data)
            {
                Next = next;
                Data = data;
            }
        }

        public MyList()
        {
            Count = 0;
        }

        private Node TakeNodeIndex(int index)
        {
            if (ThisBadIndex(index))
            {
                throw new IndexOutOfRangeException();
            }

            Node buffer = head;

            for (var i = 0; i < index; ++i)
            {
                buffer = buffer.Next;
            }

            return buffer;
        }

        private bool ThisBadIndex(int index) => index < 0 || index >= Count;

        public void Add(T item)
        {
            if (head == null)
            {
                head = new Node(null, item);
                tail = head;
            }
            else
            {
                tail.Next = new Node(null, item);
                tail = tail.Next;
            }

            ++Count;
        }

        public void Clear()
        {
            head = null;
            tail = null;
            Count = 0;
        }

        //public bool Contains(T item)
        //{
            
        //}

        public void CopyTo(T[] array, int arrayIndex)
        {
            if (arrayIndex < 0)
            {
                throw new ArgumentOutOfRangeException();
            }

            if (Count > array.Count() - arrayIndex)
            {
                throw new ArgumentException();
            }

            var buffer = head;

            while (buffer != null)
            {
                array[arrayIndex] = buffer.Data;
                buffer = buffer.Next;
                ++arrayIndex;
            }
        }

        public int IndexOf(T item)
        {
            var buffer = head;
            for (var index = 0; buffer != null; ++index) 
            {
                if (EqualityComparer<T>.Default.Equals(buffer.Data, item))
                {
                    return index;
                }
                buffer = buffer.Next;
            }

            return -1;
        }

        public void Insert(int index, T item)
        {
            if (index < 0 || index >= Count + 1) 
            {
                throw new ArgumentOutOfRangeException();
            }
            if (index == 0)
            {
                head = new Node(head, item);
            }
            else if (index == Count) 
            {
                tail.Next = new Node(null, item);
                tail = tail.Next;
            }
            else
            {
                var buffer = head;
                for (var i = 0; i < index - 1; ++i)
                {
                    buffer = buffer.Next;
                }
                buffer.Next = new Node(buffer.Next, item);
            }

            ++Count;
        }

        public bool Remove(T item)
        {
            if(head == null)
            {
                return false;
            }

            if (EqualityComparer<T>.Default.Equals(head.Data, item))
            {
                head = head.Next;
                --Count;
                return true;
            }
            else 
            {
                var buffer = head;
                while (buffer.Next != null)
                {
                    if(EqualityComparer<T>.Default.Equals(buffer.Next.Data, item))
                    {
                        if (tail == buffer.Next)
                        {
                            tail = buffer;
                        }
                        buffer.Next = buffer.Next.Next;
                        return true;
                    }
                    buffer = buffer.Next;
                }
            }
            return false;
        }



        public IEnumerator<T> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        public void RemoveAt(int index)
        {
            throw new NotImplementedException();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        

        
    }
}
