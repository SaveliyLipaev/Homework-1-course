using System;
using System.Collections.Generic;
using System.IO;

namespace _6._2
{
    class Game
    {
        private List<List<char>> map;
        private (int x, int y) characterСoordinates;

        public Game()
        {
            Console.CursorVisible = false;
            characterСoordinates.x = 10;
            characterСoordinates.y = 10;

            map = new List<List<char>>();

            for (var i = 0; i < 20; ++i)
            {
                map.Add(new List<char>());
            }

            for (var i = 0; i < 20; ++i)
            {
                for (var j = 0; j < 20; ++j)
                {
                    if (i == 0 || j == 0 || i == 19 || j == 19)
                    {
                        map[i].Add('#');
                    }
                    else
                    {
                        map[i].Add(' ');
                    }
                    Console.Write(map[i][j]);
                }
                Console.WriteLine();
            }

            this.RespCharacter(characterСoordinates.y, characterСoordinates.x);
        }

        public Game(string fileName)
        {
            Console.CursorVisible = false;
            map = new List<List<char>>();
            using (StreamReader reader = new StreamReader(fileName))
            {
                string buffer;
                for (var i = 0; (buffer = reader.ReadLine()) != null; ++i) 
                {
                    map.Add(new List<char>());
                    for (var j = 0; j < buffer.Length; ++j)
                    {
                        map[i].Add(buffer[j]);
                        if (buffer[j] == '@')
                        {
                            characterСoordinates = (j, i);
                        }
                    }
                    Console.WriteLine(buffer);
                }
            }
            RespCharacter(characterСoordinates.x, characterСoordinates.y);
        }

        public void OnLeft(object sender, EventArgs args)
        {
            if (ThereIsWall(characterСoordinates.x - 1, characterСoordinates.y))
            {
                return;
            }
            ClearCharacter();
            characterСoordinates.x -= 1;
            RespCharacter(characterСoordinates.x, characterСoordinates.y);
        }

        public void OnRight(object sender, EventArgs args)
        {
            if (ThereIsWall(characterСoordinates.x + 1, characterСoordinates.y))
            {
                return;
            }
            ClearCharacter();
            characterСoordinates.x += 1;
            RespCharacter(characterСoordinates.x, characterСoordinates.y);
        }

        public void OnUp(object sender, EventArgs args)
        {
            if (ThereIsWall(characterСoordinates.x, characterСoordinates.y - 1))
            {
                return;
            }
            ClearCharacter();
            characterСoordinates.y -= 1;
            RespCharacter(characterСoordinates.x, characterСoordinates.y);
        }

        public void OnDown(object sender, EventArgs args)
        {
            if (ThereIsWall(characterСoordinates.x, characterСoordinates.y + 1))
            {
                return;
            }
            ClearCharacter();
            characterСoordinates.y += 1;
            RespCharacter(characterСoordinates.x, characterСoordinates.y);
        }

        private void ClearCharacter()
        {
            map[characterСoordinates.y][characterСoordinates.x] = ' ';
            Console.Write(' ');
            Console.CursorLeft -= 1;
        }

        private void RespCharacter(int xCord, int yCord)
        {
            map[yCord][xCord] = '@';
            Console.CursorLeft = xCord;
            Console.CursorTop = yCord;
            Console.Write('@');
            Console.CursorLeft -= 1;
        }

        private bool ThereIsWall(int xCord, int yCord) => map[yCord][xCord] == '#';
    }
}