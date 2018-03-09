//
// Game.hh for nibbler in /home/marchi_n/rendu/cpp_nibbler
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Thu Apr  3 15:56:19 2014 Nans Marchis-Mouren
// Last update Sun Apr  6 20:08:41 2014 Nans Marchis-Mouren
//

#ifndef GAME_HH_
# define GAME_HH_

# include <sstream>
# include <vector>
# include <string>
# include <iostream>
# include "../lib/IGraphic.hh"
# include "Food.hh"
# include "Snake.hh"
# include "GraphicFactory.hh"

class		Game
{
public:

  Game(int width, int height, IGraphic*);
  ~Game();

  int		getWidth() const;
  int		getHeight() const;

  Snake*	getSnake() const;
  Food*		getFood() const;

  void		move();
  void		play();

private:

  int		_width;
  int		_height;
  Snake		*_snake;
  Food		*_food;
  IGraphic	*_lib;

};

#endif /* GAME_HH_ */
