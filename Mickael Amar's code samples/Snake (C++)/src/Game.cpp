//
// Game.cpp for nibbler in /home/marchi_n/rendu/cpp_nibbler
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Thu Apr  3 15:57:53 2014 Nans Marchis-Mouren
// Last update Sun Apr  6 23:15:48 2014 Nans Marchis-Mouren
//

#include <unistd.h>
#include <stdlib.h>
#include "Game.hh"

Game::Game(int width, int height, IGraphic *lib)
{
  _width = width;
  _height = height;
  _lib = lib;
  _snake = new Snake(width, height);
  _food = new Food(width, height);
  _snake->setFood(_food);
}

Game::~Game()
{
  delete _food;
  delete _snake;
}

void		Game::move()
{
  eEvent	event;

  event = _lib->getEvent();
  if (event == ESCAPE || event == EXIT)
    exit(0);
  if (event == LEFT)
    _snake->left();
  else if (event == RIGHT)
    _snake->right();
  else
    _snake->autoMove();
}

void		Game::play()
{
  _lib->windowInit(_width, _height);
  while (42)
    {
      _lib->refresh(_snake->getSnake(), _food->getX(), _food->getY());
      move();
      usleep(250000);
    }
}

Food*		Game::getFood() const
{
  return (_food);
}

Snake*		Game::getSnake() const
{
  return (_snake);
}

int	Game::getWidth() const
{
  return (_width);
}

int	Game::getHeight() const
{
  return (_height);
}

