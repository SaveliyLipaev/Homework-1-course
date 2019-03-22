using System;


namespace Homework_4._2
{
    public class List : IList
    {
        protected Node head;
        public int amountElements { get; private set; }
        
        protected class Node
        {
            public int data { get; set; }
            public Node next { get; set; }

            public Node(int data, Node next)
            {
                this.data = data;
                this.next = next;
            }
        }
        
        public virtual void Add(int data)
        {
            head = new Node(data, head);
            ++amountElements;
        }

        public int Remove()
        {
            if(IsEmpty())
            {
                throw new NullReferenceException("Невозможно удалить элемент, список пуст");
            }

            int buffer = head.data;
            head = head.next;
            --amountElements;
            return buffer;
        }

        public void RemoveElement(int data)
        {
            if (head != null && head.data == data)
            {
                Remove();
                return;
            }

            var element = head;
            var previousElement = head;

            while (element != null)
            {
                if (element.data == data)
                {
                    previousElement.next = element.next;
                    --amountElements;
                    return;
                }
                previousElement = element; 
                element = element.next;
            }
            throw new MissingItemException("Такого элемента не существует в списке");
        }

        public bool IsEmpty() => head == null;

    }
}
