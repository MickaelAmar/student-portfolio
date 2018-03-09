//
// Snake.cpp for Snake in /home/mika/cpp_nibbler/src
// 
// Made by mickael amar
// Login   <amar_e@epitech.net>
// 
// Started on  Sat Apr  5 15:10:16 2014 mickael amar
// Last update Sun Apr  6 23:40:19 2014 Nans Marchis-Mouren
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Snake.hh"

Snake::Snake(int width, int height)
{
  createSnake(HEAD, height / 2, width / 2);
  createSnake(BODY, (height / 2) - 1, width / 2);
  createSnake(BODY, (height / 2) - 2, width / 2);
  createSnake(TAIL, (height / 2) - 3, width / 2);
  this->_width = width;
  this->_height = height;
  this->_direction = RIGHT;
  this->_orientation = HORIZONTAL;
  this->_ate = false;
  setTail(this->_snake[3]);
}

const std::vector<t_snake>&	Snake::getSnake() const
{
  return (this->_snake);
}

void				Snake::setFood(Food *food)
{
  this->_food = food;
}

void				Snake::createSnake(eSnakeBody part, int x, int y)
{
  t_snake			snake = {part, x, y};
  
  this->_snake.push_back(snake);
}

void				Snake::displaySnake() const
{
  std::cout << "snake's size : " << this->_snake.size() << std::endl;
  for (unsigned int i = 0; i < this->_snake.size(); i += 1)
    std::cout << "Snake pos[" << i << "] :" << std::endl << 
      "Part : " << this->_snake[i].part << std::endl << 
      "X : " << this->_snake[i].x << std::endl <<
      "Y : " << this->_snake[i].y << std::endl <<
      "----------------" << std::endl <<
      std::endl;
}

void				Snake::left()
{
  if (this->_direction == RIGHT)
    moveUp();
  else if (this->_direction == LEFT)
    moveDown();
  else if (this->_direction == DOWN)
    moveRight();
  else
    moveLeft();
}

void				Snake::right()
{
  if (this->_direction == RIGHT)
    moveDown();
  else if (this->_direction == LEFT)
    moveUp();
  else if (this->_direction == DOWN)
    moveLeft();
  else
    moveRight();
}

void				Snake::moveSnake(int x, int y, eDirection dir, eOrientation ori)
{
  t_snake			part;

  this->_snake[0].part = BODY;
  this->_snake.pop_back();
  this->_snake.insert(this->_snake.begin(), part);
  this->_snake.back().part = TAIL;
  this->_snake[0].x = this->_snake[1].x + x;
  this->_snake[0].y = this->_snake[1].y + y;
  this->_snake[0].part = HEAD;
  this->_direction = dir;
  this->_orientation = ori;
}

void				Snake::moveUp()
{
  setTail(this->_snake[getTailPos()]);
  moveSnake(0, -1, UP, VERTICAL);
  if (this->_ate)
    extendSnake();
  checkFood();
  checkWall();
  checkSnake();
}

void				Snake::moveDown()
{
  setTail(this->_snake[getTailPos()]);
  moveSnake(0, 1, DOWN, VERTICAL);
  if (this->_ate)
    extendSnake();
  checkFood();
  checkWall();
  checkSnake();
}

void				Snake::moveLeft()
{
  setTail(this->_snake[getTailPos()]);
  moveSnake(-1, 0, LEFT, HORIZONTAL);
  if (this->_ate)
    extendSnake();
  checkFood();
  checkWall();
  checkSnake();
}

void				Snake::autoMove()
{
  if (this->_direction == UP)
    moveUp();
  else if (this->_direction == DOWN)
    moveDown();
  else if (this->_direction == LEFT)
    moveLeft();
  else
    moveRight();
}

void				Snake::moveRight()
{
  setTail(this->_snake[getTailPos()]);
  moveSnake(1, 0, RIGHT, HORIZONTAL);
  if (this->_ate)
    extendSnake();
  checkFood();
  checkWall();
  checkSnake();
}

int				Snake::getTailPos() const
{
  unsigned int			ret = 0;

  for (unsigned int i = 0; i < this->_snake.size(); i ++)
    ret = i;
  return (ret);
}

void				Snake::setTail(t_snake tail)
{
  this->_tail.part = tail.part;
  this->_tail.x = tail.x;
  this->_tail.y = tail.y;
}

void				Snake::checkFood()
{
  if (_snake[0].x == _food->getX() && _snake[0].y == _food->getY())
    {
      _food->putFood(this);
      this->_ate = true;
    }
}

void				Snake::extendSnake()
{
  this->_snake.push_back(this->_tail);
  this->_ate = false;
}

void				Snake::checkWall() const
{
  if ((this->_snake[0].x >= this->_width || this->_snake[0].x <= 0) ||
      (this->_snake[0].y >= this->_height || this->_snake[0].y <= 0))
    {
      std::cout << "Wall encountered" << std::endl;
      exit(0);
    }
}

void				Snake::checkSnake() const
{
  for (unsigned int i = 1; i != this->_snake.size(); i += 1)
    {
      if (this->_snake[0].x == this->_snake[i].x && this->_snake[0].y == this->_snake[i].y)
	{
	  std::cout << "Snake part encountered" << std::endl;
	  exit(0);
	}
    }
}

Snake::~Snake()
{
}
