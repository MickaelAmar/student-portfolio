//
// Food.cpp for nibbler in /home/marchi_n/rendu/cpp_nibbler/src
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Sat Apr  5 13:23:03 2014 Nans Marchis-Mouren
// Last update Sun Apr  6 23:18:40 2014 Nans Marchis-Mouren
//

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Snake.hh"
#include "Food.hh"

Food::Food(int width, int height)
{
  srand(time(0));
  this->_width = width;
  this->_height = height;
  this->_x = 0;
  this->_y = 0;
}

int		Food::getX() const
{
  return (this->_x);
}

int		Food::getY() const
{
  return (this->_y);
}

void		Food::putFood(const Snake* snake)
{  
  std::vector<t_snake>	tmp = snake->getSnake();
  
  this->_x = rand() % _width + 1;
  this->_y = rand() % _height + 1;
  for (unsigned int i = 0; i != tmp.size(); i += 1)
    {
      if (this->_x == tmp[i].x || this->_y == tmp[i].y)
	putFood(snake);
    }
}

Food::~Food()
{
}
