//
// Core.cpp for bomberman in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 14:36:43 2014 Nans Marchis-Mouren
// Last update Sun Jun 15 00:36:34 2014 ROSE
//

#include <iostream>
#include "SceneMap.hh"
#include "SceneMenu.hh"
#include "Core.hh"

Core::Core(DynEngine *engine,
	   ResourceManager* res,
	   SceneManager* sce)
{
  _engine = engine;
  _resManager = res;
  _sceManager = sce;
  //_graManager = gra;
}

Core::~Core()
{
}

bool	Core::initialize()
{
  std::cout << "PROUT" << std::endl;
  _sceManager->setScene(new SceneMenu(_engine, _resManager));
  return true;
}

int	Core::start()
{
  bool	run;

  run = true;
  std::cout << "Ici c'est la Syrie!" << std::endl;
  while (run)
    {
      run = this->update();
      //std::cout << "run(" << run << ")" << std::endl;
      this->draw();
    }
  return (0);
}

bool	Core::update()
{
  return _sceManager->tick();
}

void	Core::draw()
{
  _sceManager->render();
}
