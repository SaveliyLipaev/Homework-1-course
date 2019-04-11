using System;

namespace HomeWork_4._1
{
    /// <summary>
    /// Интерфейс дерева разбора
    /// </summary>
    interface IParseTree
    {
        /// <summary>
        /// Вычисляет и возвращает значение выражения в дереве разбора
        /// </summary>
        int Result();

        /// <summary>
        /// Возвращает выражение по которому построенно дерево
        /// </summary>
        string GetExpression();
    }
}
