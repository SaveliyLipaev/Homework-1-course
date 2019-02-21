using System;

namespace Task_1_5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Проверка на работоспособность:\n");

            Console.WriteLine($"Задание №1\nФакториал числа 6 = {Homework_1.Factorial(6)}\n");

            Console.WriteLine($"Задание №2\nДесятое число Фибоначчи = {Homework_1.Fibonachi(10)}\n");

            Console.WriteLine("Данный массив:");

            int[,] mas = { { 3, 2, 5, 3, 1 }, { 2, 5, 7, 4, 7 }, { 1, 3, 4, 6, 8 }, { 1, 6, 7, 7, 5 }, { 1, 9, 8, 0, 8 } };
            Homework_1.printMatrix(mas);

            Console.WriteLine("\nЗадание №4(проход по спирали)");
            Homework_1.SpiralWalk(mas);

            Console.WriteLine("\nЗадание №5(сортировка по первому элементу столбцов)");
            Homework_1.SortColumns(mas);
            Homework_1.printMatrix(mas);

            Console.ReadKey();
        }
    }
}
