using System;

namespace Task_1_5
{
    class Homework_1
    {
        public static int Factorial(int number)
        {
            if (number < 0)
            {
                return -1;
            }

            if (number == 0 || number == 1)
            {
                return 1;
            }

            int value = 1 ;
            for (var i = 2; i <= number; ++i)
            {
                value *= i;
            }
            return value;
        }

        public static int Fibonacсhi(int number)
        {
            if (number <= 0)
            {
                return -1;
            }
            if (number == 1) 
            {
                return 0;
            }
            int firstValue = 0;
            int secondValue = 1;
            for (var i = 2; i < number; ++i)
            {
                int buffer = secondValue;
                secondValue = secondValue + firstValue;
                firstValue = buffer;
            }
            return secondValue;
        }

        public static void Sort(int[] mas)
        {
            int length = mas.Length;
            for (var i = 1; i < length; ++i)
            {
                for (var j = length - 1; j >= i; --j)  
                {
                    if (mas[j] < mas[j - 1])
                    {
                        Swap(ref mas[j], ref mas[j - 1]);
                    }
                }
            }
        }

        private static void Swap(ref int first, ref int second)
        {
            int buffer = first;
            first = second;
            second = buffer;
        }

        public static void SpiralWalk(int[,] mas)
        {
            int length = mas.GetLength(0) - 1;

            int line = length / 2;
            int column = line;

            for (var i = length / 2; i >= 0; --i)
            {
                while (column > i)
                {
                    Console.Write($"{mas[line, column]}  ");
                    --column;
                }

                while (line < length - i)
                {
                    Console.Write($"{mas[line, column]}  ");
                    ++line;
                }

                while (column < length - i)
                {
                    Console.Write($"{mas[line, column]}  ");
                    ++column;
                }

                while (line >= i)
                {
                    Console.Write($"{mas[line, column]}  ");
                    --line;
                }
            }
            Console.WriteLine();
        }

        private static void SwapColumns(int[,] matrix, int firstIndex, int secondIndex)
        {
            for (var i = 0; i < matrix.GetLength(0); ++i)
            {
                Swap(ref matrix[i, firstIndex], ref matrix[i, secondIndex]);
            }
        }

        public static void SortColumns(int[,] matrix)
        {
            for (var i = 1; i < matrix.GetLength(1); ++i)
            {
                for (var j = matrix.GetLength(1) - 1; j >= i; --j)
                {
                    if (matrix[0, j] < matrix[0, j - 1])
                    {
                        SwapColumns(matrix, j, j - 1);
                    }
                }
            }
        }

        public static void printMatrix(int[,] matrix)
        {
            for (var i = 0; i < matrix.GetLength(0); ++i)
            {
                for (var j = 0; j < matrix.GetLength(1); ++j)
                {
                    Console.Write($"{matrix[i, j]}  ");
                }
                Console.WriteLine();
            }
        }
    }
}
