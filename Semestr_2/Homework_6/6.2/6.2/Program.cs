using System;
using System.IO;

namespace _6._2
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                var eventLoop = new EventLoop();
                var game = new Game(@"..\..\Map.txt");

                eventLoop.DownHandler += game.OnDown;
                eventLoop.LeftHandler += game.OnLeft;
                eventLoop.RightHandler += game.OnRight;
                eventLoop.UpHandler += game.OnUp;

                eventLoop.DownHandler += game.PrintGame;
                eventLoop.LeftHandler += game.PrintGame;
                eventLoop.UpHandler += game.PrintGame;
                eventLoop.RightHandler += game.PrintGame;

                eventLoop.Run();
            }
            catch(UnforeseenMapSymbolException e)
            {
                Console.Clear();
                Console.WriteLine(e);
            }
            catch(TwoHeroOnMapException e)
            {
                Console.Clear();
                Console.WriteLine(e);
            }
            catch(ArgumentOutOfRangeException e)
            {
                Console.Clear();
                Console.WriteLine("Неправильно составленная карта");
            }
            catch(FileNotFoundException e)
            {
                Console.Clear();
                Console.WriteLine(e);
            }
        }
    }
}
