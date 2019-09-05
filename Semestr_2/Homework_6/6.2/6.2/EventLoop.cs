using System;

namespace _6._2
{
    /// <summary>
    /// Класс реализующий цикл обработки событий
    /// </summary>
    class EventLoop
    {
        public event EventHandler<KeyEventArgs> LeftHandler = (sender, args) => { };
        public event EventHandler<KeyEventArgs> RightHandler = (sender, args) => { };
        public event EventHandler<KeyEventArgs> UpHandler = (sender, args) => { };
        public event EventHandler<KeyEventArgs> DownHandler = (sender, args) => { };

        /// <summary>
        /// Метод запускает цикл обработки событий
        /// </summary>
        public void Run()
        {
            while (true)
            {
                var key = Console.ReadKey(true);
                switch (key.Key)
                {
                    case ConsoleKey.LeftArrow:
                        LeftHandler(this, new KeyEventArgs(key.Key));
                        break;
                    case ConsoleKey.RightArrow:
                        RightHandler(this, new KeyEventArgs(key.Key));
                        break;
                    case ConsoleKey.UpArrow:
                        UpHandler(this, new KeyEventArgs(key.Key));
                        break;
                    case ConsoleKey.DownArrow:
                        DownHandler(this, new KeyEventArgs(key.Key));
                        break;
                }
            }
        }
    }
}
