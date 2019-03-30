using System;

namespace HomeWork_4._1
{
    interface IParseTree
    {
        /// <summary>
        /// Вычисляет и возвращает значение выражения в дереве разбора
        /// </summary>
        /// <returns></returns>
        int Result();

        /// <summary>
        /// Возвращает выражение по которому построенно дерево
        /// </summary>
        /// <returns></returns>
        string GetExpression();
    }
}
