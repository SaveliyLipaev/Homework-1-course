using System;

namespace HomeWork_4._1
{
    public class ParseTree : IParseTree
    {
        private Node head;
        private string[] expression;

        private abstract class Node
        {
            abstract public int Calculate();
            abstract public void Print();
            public abstract override string ToString();
        }

        private class Operator : Node
        {
            public Node Left { get; set; }
            public Node Right { get; set; }
            public string Symbol { get; set; }

            public Operator(string symbol)
            {
                Symbol = symbol;
            }

            public override int Calculate() => CalculateExpression(this.Left) + CalculateExpression(this.Right);

            public override void Print() => Console.Write(Symbol);

            public override string ToString() => Symbol;
        }

        private class Operand : Node
        {
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
            head = СreatureNode(ref index);
        }

        private Node СreatureNode(ref int index)
        {
            ++index;
            if (expression[index] == "(")
            {

                if(int.TryParse(expression[index + 1], out int buffer) )
                {
                    throw new ArgumentException("Невозможно преобразовать выражение в дерево");
                }

                var newNode = new Operator(expression[++index]);

                newNode.Left = СreatureNode(ref index);

                newNode.Right = СreatureNode(ref index);

                return newNode;
            }
            else if (int.TryParse(expression[index], out int operand))
            {
                return new Operand(operand);
            }
            else if (expression[index] == ")")
            {
                return СreatureNode(ref index);
            }
            else
            {
                throw new ArgumentException("Невозможно преобразовать выражение в дерево");
            }
        }

        private static int CalculateExpression(Node node)
        {
            try
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
            catch
            {
                throw;
            }
        }

        public int Result()
        {
            return CalculateExpression(head);
        }

        public string GetExpression()
        {
            string result = null;
            foreach(var i in expression)
            {
                result += i + ' ';
            }
            return result;
        }
    }
}