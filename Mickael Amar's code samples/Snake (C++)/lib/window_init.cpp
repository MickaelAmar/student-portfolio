//
// window_init.cpp for SDL in /home/jausse_c/rendu/CPP/cpp_nibbler/lib
// 
// Made by Jausselme
// Login   <jausse_c@epitech.net>
// 
// Started on  Sat Apr  5 15:13:12 2014 Jausselme
// Last update Sun Apr  6 23:40:01 2014 Nans Marchis-Mouren
//

#include "window_init.hh"

LibSdl::LibSdl()
{
  this->_screen = NULL;
  this->_part = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 20, 32, 0, 0, 0, 0);
  this->_x = 0;
  this->_y = 0;
}

LibSdl::~LibSdl()
{

}

void             LibSdl::windowInit(int width, int height)
{
  SDL_Surface           *screen;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      std::cout << "Error : init SDL failed" << std::endl;
      exit(0);
    }
  screen = SDL_SetVideoMode(width * 20, height * 20, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen == NULL)
    {
      std::cout << "Error : set video mode failure" << std::endl;
      exit(0);
    }
  SDL_WM_SetCaption("Nibbler", NULL);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_Flip(screen);
  setScreen(screen);
}

eEvent            LibSdl::getEvent() const
{
  SDL_Event     event;

  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT)
    return (EXIT);
  else if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_RIGHT)
	return (RIGHT);
      if (event.key.keysym.sym == SDLK_LEFT)
	return (LEFT);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (ESCAPE);
    }
  return (NONE);
}

void		LibSdl::setPos(int x, int y)
{
  this->_x = x * 20;
  this->_y = y * 20;
}

void		LibSdl::setScreen(SDL_Surface *screen)
{
  this->_screen = screen;
}

void		LibSdl::refresh(std::vector<t_snake> snake, int x, int y)
{
  unsigned int	i;

  i = 0;
  SDL_FillRect(_screen, NULL, SDL_MapRGB(_screen->format, 0, 0, 0));
  SDL_Flip(_screen);
  while (i < snake.size())
    {
      setPos(snake[i].x, snake[i].y);
      blitPartSnake(snake[i]);
      i++;
    }
  blitFood(x, y);
}

void		LibSdl::blitPartSnake(t_snake body)
{
  SDL_Rect	pos;

  pos.x = this->_x;
  pos.y = this->_y;
  if (body.part == HEAD)
    {
      if ((this->_part = IMG_Load("lib/img/HeadSnakeRight.png")) == NULL)
	{
	  std::cout << "Error : can't load img" << std::endl;
	  exit(0);
	}   
    }
  else 
    {
      if ((this->_part = IMG_Load("lib/img/BodySnake.png")) == NULL)
	{
	  std::cout << "Error : can't load img" << std::endl;
	  exit(0);
	}
    }
  SDL_BlitSurface(this->_part, NULL, this->_screen, &pos);
  SDL_Flip(this->_screen);
}

void		LibSdl::blitFood(int x, int y)
{
  SDL_Rect	pos;

  pos.x = x * 20;
  pos.y = y * 20;
  if ((this->_part = IMG_Load("lib/img/Fruit.jpg")) == NULL)
    {
      std::cout << "Error : can't load img" << std::endl;
      exit(0);
    }
  SDL_BlitSurface(this->_part, NULL, this->_screen, &pos);
  SDL_Flip(this->_screen);
}
