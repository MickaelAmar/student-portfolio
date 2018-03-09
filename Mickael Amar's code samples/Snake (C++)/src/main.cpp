//
// main.cpp for main in /home/mika/cpp_nibbler/src
// 
// Made by mickael amar
// Login   <amar_e@epitech.net>
// 
// Started on  Sat Apr  5 12:53:41 2014 mickael amar
// Last update Sun Apr  6 22:44:58 2014 Jausselme
//

#include <iostream>
#include <string.h>
#include "Game.hh"

int			main(int ac, char **av)
{
  int			width;
  int			height;
  Game			*game;
  IGraphic		*lib = NULL;
  GraphicFactory	gf(av[3]);


  if (ac != 4)
    {
      std::cerr << "Usage : " << av[0] << " [width : 10-50] [height : 10-50]" << 
	" lib_nibbler_[sdl|qt].so" << std::endl;
      return (1);
    }

  std::istringstream	firstBuffer(av[1]);
  std::istringstream	secondBuffer(av[2]);
  std::string		str(av[3]);

  if (!(firstBuffer >> width) || !(secondBuffer >> height))
    {
      std::cout << "Conversion error" << std::endl; // ParamException here
      return (1);
    }
  if (width > 50 || width < 10 || height > 50 || height < 10)
    {
      std::cout << "Bad width or height number" << std::endl; // ParamException here
      return (1);
    }
  /*  if (str != "lib_nibbler_sdl.so")
    {
      std::cout << "Bad library name" << std::endl; // ParamException here
      return (1);
      }*/
  lib = gf.getLib();
  game = new Game(width, height, lib);
  game->getFood()->putFood(game->getSnake());
  game->play();
  game->getSnake()->displaySnake();
  delete game;
  return (0);
}
