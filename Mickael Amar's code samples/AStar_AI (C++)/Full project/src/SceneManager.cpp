//
// SceneManager.cpp for SceneManager in /home/ferrie_j/Desktop/cpp_bomberman
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Thu Jun  5 16:12:03 2014 Justin Ferrieu
// Last update Sun Jun 15 02:11:54 2014 ROSE
//

#include "SceneManager.hh"
#include "ResourceManager.hh"
#include "IScene.hpp"

SceneManager::SceneManager()
{
  _curScene = 0;
}

SceneManager::~SceneManager()
{
  if (_curScene)
    delete _curScene;
}

void		SceneManager::setScene(IScene *newScene)
{
  if (_curScene)
    delete _curScene;
  _curScene = newScene;
  _curScene->initialize();
  std::cout << "INIT" << std::endl;
}

bool		SceneManager::tick()
{
  if (_curScene->getScene() != NULL)
    setScene(_curScene->getScene());
  return _curScene->tick();
}

void		SceneManager::render()
{
  _curScene->render();
}
