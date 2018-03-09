//
// sdl_manager.cpp for SDL in /home/jausse_c/rendu/CPP/cpp_nibbler/lib
// 
// Made by Jausselme
// Login   <jausse_c@epitech.net>
// 
// Started on  Sun Apr  6 15:44:21 2014 Jausselme
// Last update Tue Apr  8 12:01:52 2014 mickael amar
//

#include "IGraphic.hh"
#include "sdl_manager.hh"

SdlManager::SdlManager()
{

}

SdlManager::~SdlManager()
{

}

void			SdlManager::openWindow(LibSdl lib, int width, int height)
{
  lib.windowInit(width, height);
}

void			SdlManager::getEvent(LibSdl lib) const
{
  lib.getEvent();
}

void			SdlManager::createPartSnake(LibSdl lib, std::vector<t_snake> snake, int x, int y)
{
  lib.refresh(snake, x, y);
}

extern "C"
{
  IGraphic*	CREATLIB()
  {
    IGraphic	*lib;
    lib = new SdlManager();
    return (lib);
  }
}
