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

        public static int Fibonachi(int number)
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

        public class Matrix
        {
            private int[,] matrix;
            private int lines;
            private int columns;

            public Matrix(int[,] _matrix)
            {
                matrix = _matrix;
                lines = matrix.GetUpperBound(0) + 1;
                columns = matrix.Length / lines;
            }

            private void SwapColumns(int firstIndex, int secondIndex)
            {
                for (var i = 0; i < lines; ++i)
                {
                    Swap(ref matrix[i, firstIndex], ref matrix[i, secondIndex]);
                }
            }

            public void SortColumns()
            {
                for (var i = 1; i < columns; ++i)
                {
                    for (var j = columns - 1; j >= i; --j)
                    {
                        if (matrix[0, j] < matrix[0, j - 1]) 
                        {
                            SwapColumns(j, j - 1);
                        }
                    }
                }
            }

            public void printMatrix()
            {
                for (var i = 0; i < lines; ++i)
                {
                    for (var j = 0; j < columns; ++j)
                    {
                        Console.Write($"{matrix[i, j]}  ");
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}
