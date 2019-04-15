using System;

namespace _6._2
{
    /// <summary>
    /// Хранит введеный ключ с клавиатуры
    /// </summary>
    public class KeyEventArgs : EventArgs
    {
        public ConsoleKey Key { get; private set; }

        public KeyEventArgs(ConsoleKey key)
        {
            Key = key;
        }
    }
}
