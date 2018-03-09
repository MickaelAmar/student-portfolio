//
// sdl_manager.hh for SDL in /home/jausse_c/rendu/CPP/cpp_nibbler/lib
// 
// Made by Jausselme
// Login   <jausse_c@epitech.net>
// 
// Started on  Sun Apr  6 13:46:49 2014 Jausselme
// Last update Sun Apr  6 22:50:17 2014 Jausselme
//

#ifndef SDL_MANAGER_HH_
# define SDL_MANAGER_HH_

#include "window_init.hh"

class		SdlManager: public LibSdl
{
public:

  SdlManager();
  ~SdlManager();
  
  void		openWindow(LibSdl, int, int);
  void		getEvent(LibSdl) const;
  void		createPartSnake(LibSdl, std::vector<t_snake>, int, int);
};

#endif
