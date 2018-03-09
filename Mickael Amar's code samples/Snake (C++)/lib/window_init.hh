//
// window_init.hh for SDL in /home/jausse_c/rendu/CPP/cpp_nibbler/lib
// 
// Made by Jausselme
// Login   <jausse_c@epitech.net>
// 
// Started on  Sat Apr  5 15:15:20 2014 Jausselme
// Last update Sun Apr  6 22:47:47 2014 Jausselme
//

#ifndef WINDOW_INIT_HH_
# define WINDOW_INIT_HH_

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <iostream>
# include <vector>
# include "../src/nibbler.h"
# include "../src/Food.hh"
# include "IGraphic.hh"

class		LibSdl : public IGraphic
{
public:
  
  LibSdl();
  ~LibSdl();
  void		windowInit(int, int);
  eEvent	getEvent() const;
  void		refresh(std::vector<t_snake>, int, int);
  void		blitPartSnake(t_snake);
  void		blitFood(int, int);
  
  void		setPos(int, int);
  void		setScreen(SDL_Surface *);
  
private:

  SDL_Surface	*_screen;
  SDL_Surface	*_part;
  int		_x;
  int		_y;
};

#endif
