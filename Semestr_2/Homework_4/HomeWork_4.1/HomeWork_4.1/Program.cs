using System;
using System.IO;

namespace HomeWork_4._1
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                string expression;
                using (var readFile = new StreamReader("FileForExpression.txt"))
                {
                    expression = readFile.ReadToEnd();
                }

                var tree = new ParseTree(expression);

                Console.WriteLine(tree.GetExpression());
                Console.WriteLine(tree.Result());
            }
            catch
            {

            }
        }
    }
}
