using System;
using System.Collections.Generic;
using System.IO;

namespace _6._2
{
    /// <summary>
    /// Класс реализующий механику игры, а так же рисует все на консоль
    /// </summary>
    public class Game
    {
        private List<List<char>> map;
        private bool gameHasBegun = false;
        public int CharacterСoordinatesX { get; private set; }
        public int CharacterСoordinatesY { get; private set; }

        /// <summary>
        /// Конструктор, выгружает из файла, имя которое введено, и заполняет map
        /// </summary>
        public Game(string fileName)
        {
            bool heroOnMap = false;
            map = new List<List<char>>();
            using (StreamReader reader = new StreamReader(fileName))
            {
                string buffer;
                for (var i = 0; (buffer = reader.ReadLine()) != null; ++i) 
                {
                    map.Add(new List<char>());
                    for (var j = 0; j < buffer.Length; ++j)
                    {
                        if (buffer[j] == '@')
                        {
                            if (heroOnMap)
                            {
                                throw new TwoHeroOnMapException("Два персонажа на карте, ошибка!!");
                            }
                            CharacterСoordinatesX = j;
                            CharacterСoordinatesY = i;
                            heroOnMap = true;
                        }
                        else if (IsBadSymbols(buffer[j]))
                        {
                            throw new UnforeseenMapSymbolException("Ошибка в загруженной карте, непредвиденные символы");
                        }
                        map[i].Add(buffer[j]);
                    }
                }
            }
            RespCharacter(CharacterСoordinatesX, CharacterСoordinatesY);
            Console.WriteLine("Управление: стрелочки клавиатуры\nДля того чтобы начать нажмите на любую из стрелочек");
        }

       /// <summary>
       /// Возвращает true если символ не входит в список дпоустимых символов
       /// </summary>
        private bool IsBadSymbols(char symbol) => symbol != '@' && symbol != ' ' && symbol != '#';

        /// <summary>
        /// Метод рисует передвижение персонажа
        /// </summary>
        public void PrintGame(object sender, KeyEventArgs args)
        {
            if (!gameHasBegun)
            {
                ClearAllAndPrintMap();
                gameHasBegun = true;
                Console.CursorVisible = false;
            }
            else if (args.Key == ConsoleKey.LeftArrow) 
            {
                PrintCage(CharacterСoordinatesX + 1, CharacterСoordinatesY);
                PrintCage(CharacterСoordinatesX, CharacterСoordinatesY);
            }
            else if (args.Key == ConsoleKey.RightArrow)
            {
                PrintCage(CharacterСoordinatesX - 1, CharacterСoordinatesY);
                PrintCage(CharacterСoordinatesX, CharacterСoordinatesY);
            }
            else if (args.Key == ConsoleKey.UpArrow)
            {
                PrintCage(CharacterСoordinatesX, CharacterСoordinatesY + 1);
                PrintCage(CharacterСoordinatesX, CharacterСoordinatesY);
            }
            else if (args.Key == ConsoleKey.DownArrow)
            {
                PrintCage(CharacterСoordinatesX, CharacterСoordinatesY - 1);
                PrintCage(CharacterСoordinatesX, CharacterСoordinatesY);
            }
        }

        /// <summary>
        /// Печатает в консоль координату из карты
        /// </summary>
        /// <param name="xCord"></param>
        /// <param name="yCord"></param>
        private void PrintCage(int xCord, int yCord)
        {
            Console.CursorLeft = xCord;
            Console.CursorTop = yCord;
            Console.Write(map[yCord][xCord]);
        }

        /// <summary>
        /// Чистит консоль и распечатывает map
        /// </summary>
        private void ClearAllAndPrintMap()
        {
            Console.Clear();
            for (var i = 0; i < map.Count; ++i)
            {
                for (var j = 0; j < map[i].Count; ++j)
                {
                    Console.Write(map[i][j]);
                }
                Console.WriteLine();
            }
        }

        /// <summary>
        /// Шаг влево
        /// </summary>
        public void OnLeft(object sender, EventArgs args)
        {
            if (ThereIsWall(CharacterСoordinatesX - 1, CharacterСoordinatesY))
            {
                return;
            }
            KillCharacter();
            CharacterСoordinatesX -= 1;
            RespCharacter(CharacterСoordinatesX, CharacterСoordinatesY);
        }

        /// <summary>
        /// Шаг вправо
        /// </summary>
        public void OnRight(object sender, EventArgs args)
        {
            if (ThereIsWall(CharacterСoordinatesX + 1, CharacterСoordinatesY))
            {
                return;
            }
            KillCharacter();
            CharacterСoordinatesX += 1;
            RespCharacter(CharacterСoordinatesX, CharacterСoordinatesY);
        }

        /// <summary>
        /// Шаг вверх
        /// </summary>
        public void OnUp(object sender, EventArgs args)
        {
            if (ThereIsWall(CharacterСoordinatesX, CharacterСoordinatesY - 1))
            {
                return;
            }
            KillCharacter();
            CharacterСoordinatesY -= 1;
            RespCharacter(CharacterСoordinatesX, CharacterСoordinatesY);
        }

        /// <summary>
        /// Шаг вниз
        /// </summary>
        public void OnDown(object sender, EventArgs args)
        {
            if (ThereIsWall(CharacterСoordinatesX, CharacterСoordinatesY + 1))
            {
                return;
            }
            KillCharacter();
            CharacterСoordinatesY += 1;
            RespCharacter(CharacterСoordinatesX, CharacterСoordinatesY);
        }

        /// <summary>
        /// Стерает персонажа с карты
        /// </summary>
        private void KillCharacter() => map[CharacterСoordinatesY][CharacterСoordinatesX] = ' ';

        /// <summary>
        /// СОздает персонажа в заданном месте
        /// </summary>
        private void RespCharacter(int xCord, int yCord) => map[yCord][xCord] = '@';

        /// <summary>
        /// Возвращает true если в введеной клетке стена
        /// </summary>
        private bool ThereIsWall(int xCord, int yCord) => map[yCord][xCord] == '#';
    }
}