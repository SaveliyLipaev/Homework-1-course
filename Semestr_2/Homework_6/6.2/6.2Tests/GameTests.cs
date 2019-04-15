using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace _6._2.Tests
{
    [TestClass]
    public class GameTests
    {
        private Game game;

        [TestInitialize]
        public void Initialize()
        {
            game = new Game(@"..\..\MapForTest.txt");
        }

        [TestMethod]
        public void GameXCoordinatesInitilizeTest()
        {
            Assert.AreEqual(2, game.CharacterСoordinatesX);
        }

        [TestMethod]
        public void GameYCoordinatesInitilizeTest()
        {
            Assert.AreEqual(2, game.CharacterСoordinatesY);
        }

        [TestMethod]
        public void OnLeftTest()
        {
            game.OnLeft(this, EventArgs.Empty);
            Assert.AreEqual((1, 2), (game.CharacterСoordinatesX, game.CharacterСoordinatesY));
        }

        [TestMethod]
        public void OnRightTest()
        {
            game.OnRight(this, EventArgs.Empty);
            Assert.AreEqual((3, 2), (game.CharacterСoordinatesX, game.CharacterСoordinatesY));
        }

        [TestMethod]
        public void OnDownTest()
        {
            game.OnDown(this, EventArgs.Empty);
            Assert.AreEqual((2, 3), (game.CharacterСoordinatesX, game.CharacterСoordinatesY));
        }

        [TestMethod]
        public void OnUpTest()
        {
            game.OnUp(this, EventArgs.Empty);
            Assert.AreEqual((2, 1), (game.CharacterСoordinatesX, game.CharacterСoordinatesY));
        }

        [TestMethod]
        public void IntoTheWallTest()
        {
            game.OnLeft(this, EventArgs.Empty);
            game.OnLeft(this, EventArgs.Empty);
            game.OnLeft(this, EventArgs.Empty);
            game.OnLeft(this, EventArgs.Empty);
            game.OnLeft(this, EventArgs.Empty);
            Assert.AreEqual((1, 2), (game.CharacterСoordinatesX, game.CharacterСoordinatesY));
        }

        [TestMethod]
        [ExpectedException(typeof(TwoHeroOnMapException))]
        public void TwoHeroOnMapTest()
        {
            game = new Game(@"..\..\BadMapTest.txt");
        }

        [TestMethod]
        [ExpectedException(typeof(UnforeseenMapSymbolException))]
        public void BadSymbolOnMapTest()
        {
            game = new Game(@"..\..\BadMap2Test.txt");
        }
    }
}