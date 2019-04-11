using System;


namespace Homework_4._2
{
    /// <summary>
    /// Класс реализующий список
    /// </summary>
    public class List : IList
    {
        protected Node head;

        /// <summary>
        /// Свойство хранящее количесвто элементов в списке
        /// </summary>
        public int amountElements { get; private set; }
        
        /// <summary>
        /// Класс реализующий элемент списка
        /// </summary>
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
        
        /// <summary>
        /// Добавление в список элемента в начало
        /// </summary>
        public virtual void Add(int data)
        {
            head = new Node(data, head);
            ++amountElements;
        }

        /// <summary>
        /// ВОзвращает и удляет первый элемент списка
        /// </summary>
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

        /// <summary>
        /// Удаляет элемент из списка, если элемент не найден кидает исключение
        /// </summary>
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

        /// <summary>
        /// Возвращает true если список пуст
        /// </summary>
        public bool IsEmpty() => head == null;

    }
}
