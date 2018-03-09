//
// GraphicFactory.cpp for nibbler in /home/marchi_n/rendu/cpp_nibbler/src
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Sun Apr  6 19:40:45 2014 Nans Marchis-Mouren
// Last update Sun Apr  6 23:40:48 2014 Nans Marchis-Mouren
//

#include <dlfcn.h>
#include <stdlib.h>
#include "GraphicFactory.hh"

GraphicFactory::GraphicFactory(const char *path)
{
  void		*dlhandle;
  IGraphic	*(*tmp)();

  dlhandle = dlopen(path, RTLD_LAZY);
  if (dlhandle == NULL)
    exit(0);
  tmp = reinterpret_cast<IGraphic * (*)()>(dlsym(dlhandle, "CREATLIB"));
  if (tmp == NULL)
    exit(0);
  this->_lib = (*tmp)();
}

IGraphic	*GraphicFactory::getLib() const
{
  return (_lib);
}

GraphicFactory::~GraphicFactory()
{

}

