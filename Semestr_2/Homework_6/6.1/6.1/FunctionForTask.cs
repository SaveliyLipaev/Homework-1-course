using System;
using System.Collections.Generic;

namespace _6._1
{
    /// <summary>
    /// Класс, реализующий функции Map, Filter, Fold из домашки
    /// </summary>
    public static class FunctionForTask
    {
        /// <summary>
        /// Map принимает список и функцию, преобразующую элемент списка,
        /// возвращается список, полученный применением переданной 
        /// функции к каждому элементу переданного списка
        /// </summary>
        public static List<int> Map(List<int> list, Func<int, int> func)
        {
            var newList = new List<int>();

            foreach(var element in list)
            {
                newList.Add(func(element));
            }

            return newList;
        }

        /// <summary>
        /// Filter принимает список и функцию, возвращающую булевое значение 
        /// по элементу списка. Возвращается список, составленный из 
        /// тех элементов переданного списка, для которых переданная функция вернула true
        /// </summary>
        public static List<int> Filter(List<int> list, Func<int, bool> func)
        {
            var newList = new List<int>();

            foreach (var element in list)
            {
                if (func(element))
                {
                    newList.Add(element);
                }
            }

            return newList;
        }

        /// <summary>
        /// Fold принимает список, начальное значение и функцию, которая берёт 
        /// текущее накопленное значение и текущий элемент списка, и возвращает 
        /// следующее накопленное значение. Сама Fold возвращает накопленное значение,
        /// получившееся после всего прохода списка
        /// </summary>
        public static int Fold(List<int> list, int presentValue, Func<int, int, int> func)
        {
            foreach (var element in list)
            {
                presentValue = func(presentValue, element);
            }

            return presentValue;
        }
    }
}
