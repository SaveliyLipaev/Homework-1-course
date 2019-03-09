using System;

namespace Homework_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var calc = new StackCalculator(new ListStackInt());

            Console.WriteLine(calc.DoCalculation("4 43 + 5 6 * -"));
            
        }
    }
}
