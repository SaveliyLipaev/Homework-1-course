using System;

namespace HomeWork_4._1
{
    /// <summary>
    /// Класс реализующий дерево разбора арифметического выражения
    /// </summary>
    public class ParseTree : IParseTree
    {
        private Node head;
        private string[] expression;

        /// <summary>
        /// Класс реализующий узел в дереве
        /// </summary>
        private abstract class Node
        {
            /// <summary>
            /// Функция производящая подсчет в данном узле
            /// </summary>
            /// <returns></returns>
            abstract public int Calculate();

            /// <summary>
            /// распечатывает узел
            /// </summary>
            abstract public void Print();

            public abstract override string ToString();
        }

        /// <summary>
        /// Класс реализующий оператор
        /// </summary>
        private class Operator : Node
        {
            /// <summary>
            /// Свойство - левый сын
            /// </summary>
            public Node Left { get; set; }

            /// <summary>
            /// Свойство - правый сын
            /// </summary>
            public Node Right { get; set; }

            /// <summary>
            /// Свойство - символ оператора
            /// </summary>
            public string Symbol { get; set; }

            public Operator(string symbol)
            {
                Symbol = symbol;
            }

            public override int Calculate() => DoOperation.Arithmetic.Result(CalculateExpression(this.Left), CalculateExpression(this.Right), Symbol);

            public override void Print() => Console.Write(Symbol);

            public override string ToString() => Symbol;
        }

        /// <summary>
        /// Класс реализующий операнд
        /// </summary>
        private class Operand : Node
        {
            /// <summary>
            /// Свойство хранящее значение в узле
            /// </summary>
            public int Data { get; set; }

            public Operand(int data)
            {
                Data = data;
            }

            public override int Calculate() => Data;

            public override void Print() => Console.Write(Data);

            public override string ToString() => Data.ToString();
        }

        public ParseTree(string expression)
        {
            this.expression = expression.Split(' ');
            int index = -1;
            int counterNumber = 0;
            head = СreateNode(ref index, ref counterNumber);
        }

        /// <summary>
        /// Функция для рекурсивного заполнения дерева
        /// </summary>
        /// <param name="index">номер обрабатываемого в строке символа</param>
        /// <param name="counterNumber">колличество чисел идущих подряд</param>
        private Node СreateNode(ref int index, ref int counterNumber)
        {
            ++index;
            if (expression[index] == "(")
            {
                if (int.TryParse(expression[index + 1], out int buffer)) 
                {
                    throw new ArgumentException("Невозможно преобразовать выражение в дерево");
                }

                counterNumber = 0;

                ++index;
                var newNode = new Operator(expression[index]);

                newNode.Left = СreateNode(ref index, ref counterNumber);

                newNode.Right = СreateNode(ref index, ref counterNumber);

                return newNode;
            }
            else if (int.TryParse(expression[index], out int operand))
            {
                ++counterNumber;

                if(counterNumber == 3)
                {
                    throw new ArgumentException("Невозможно преобразовать выражение в дерево");
                }

                return new Operand(operand);
            }
            else if (expression[index] == ")")
            {
                counterNumber = 0;
                return СreateNode(ref index, ref counterNumber);
            }
            else
            {
                throw new ArgumentException("Невозможно преобразовать выражение в дерево");
            }
        }

        /// <summary>
        /// Функция возвращающая посчитанное значение в данном узле
        /// </summary>
        private static int CalculateExpression(Node node)
        {
            if (int.TryParse(node.ToString(), out int number))
            {
                return number;
            }
            else
            {
                return DoOperation.Arithmetic.Result(CalculateExpression((node as Operator).Left), CalculateExpression((node as Operator).Right), node.ToString());
            }
        }

        /// <summary>
        /// Функция возвращающая посчитанное дерево разбора
        /// </summary>
        public int Result() => CalculateExpression(head);

        /// <summary>
        /// Функция распечатывающая изначально выражение
        /// </summary>
        public string GetExpression()
        {
            string result = null;
            foreach (var i in expression) 
            {
                result += i + ' ';
            }
            return result;
        }
    }
}