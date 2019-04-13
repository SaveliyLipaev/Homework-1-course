using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _6._2
{
    class Program
    {
        static void Main(string[] args)
        {
            var eventLoop = new EventLoop();
            var game = new Game("Map.txt");
          

            eventLoop.DownHandler += game.OnDown;
            eventLoop.LeftHandler += game.OnLeft;
            eventLoop.RightHandler += game.OnRight;
            eventLoop.UpHandler += game.OnUp;

            eventLoop.Run();
        }
    }
}
