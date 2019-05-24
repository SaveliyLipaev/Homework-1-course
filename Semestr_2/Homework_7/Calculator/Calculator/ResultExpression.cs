using System;
using System.Collections.Generic;

namespace Calculator
{
    /// <summary>
    /// Класс реализующий вычисление выражения
    /// </summary>
    public static class ResultExpression
    {
        public static double Result(string expression)
        {
            var postfix = InPostfixForm(ParseExpression(expression));
            return CalculatePostfix(postfix);
        }

        /// <summary>
        /// Функция парсит данную строку
        /// </summary>
        private static List<string> ParseExpression(string expression)
        {
            var list = new List<string>();
            string buffer = string.Empty;
            foreach (var symbol in expression)
            {
                if (symbol >= '0' && symbol <= '9' || symbol == ',')
                {
                    buffer += symbol;
                }
                else if (IsOperator(symbol.ToString()) || symbol.ToString() == ")" || symbol.ToString() == "(")
                {
                    if (buffer != string.Empty)
                    {
                        list.Add(buffer);
                        buffer = string.Empty;
                    }

                    list.Add(symbol.ToString());
                }
            }
            if (buffer != string.Empty)
            {
                list.Add(buffer);
            }
            return list;
        }

        private static bool IsOperator(string ch) => ch == "+" || ch == "*" || ch == "/" || ch == "-";

        /// <summary>
        /// Функция переводит строку в постфиксную форму
        /// </summary>
        private static string InPostfixForm(List<string> expression)
        {
            var stack = new Stack<string>();
            expression.Insert(0, "(");
            expression.Add(")");
            string postfix = string.Empty;

            for (var index = 0; index < expression.Count;) 
            {
                if (expression[index] == "(")
                {
                    stack.Push("(");
                    ++index;
                }
                else if (expression[index] == "*" || expression[index] == "/")
                {
                    if (stack.Peek() == "*" || stack.Peek() == "/")
                    {
                        postfix += stack.Pop() + " ";
                    }
                    else
                    {
                        stack.Push(expression[index]);
                        ++index;
                    }
                }
                else if (expression[index] == "+" || expression[index] == "-")
                {
                    if (stack.Count == 0 || stack.Peek() == "(")
                    {
                        stack.Push(expression[index]);
                        ++index;
                    }
                    else
                    {
                        postfix += stack.Pop() + " ";
                    }
                }
                else if (expression[index] == ")")
                {
                    if (stack.Peek() == "(")
                    {
                        stack.Pop();
                        ++index;
                    }
                    else
                    {
                        postfix += stack.Pop() + " ";
                    }
                }
                else if (double.TryParse(expression[index], out double _)) 
                {
                    postfix += expression[index] + " ";
                    ++index;
                }
            }

            if (stack.Count != 0)
            {
                throw new ArgumentException("Не удалось перевести выражение в постфиксную форму");
            }

            return postfix;
        }
        
        /// <summary>
        /// Функция, вычисляющая выражение в постфиксной форме
        /// </summary>
        private static double CalculatePostfix(string expression)
        {
            var stack = new Stack<double>();
            string[] literals = expression.Split(' ');
            foreach (var literal in literals)
            {
                if (double.TryParse(literal, out double result))
                {
                    stack.Push(result);
                }
                else if (IsOperator(literal))
                {
                    double secondNumber = stack.Pop();
                    double firstNumber = stack.Pop();
                    stack.Push(DoOperation(firstNumber, secondNumber, literal));
                }
            }

            var buffer = stack.Pop();
            if (stack.Count != 0)
            {
                throw new ArgumentException("Невозможно вычислить, проверьте правильность записи");
            }

            return buffer;
        }

        private static double DoOperation(double firstNumber, double secondNumber, string operation)
        {
            switch (operation)
            {
                case "+":
                    return firstNumber + secondNumber;
                case "-":
                    return firstNumber - secondNumber;
                case "*":
                    return firstNumber * secondNumber;
                case "/":
                    if (secondNumber == 0) 
                    {
                        throw new DivideByZeroException();
                    }
                    return firstNumber / secondNumber;
            }
            return 0;
        }
    }
}
