//
// ResourceManager.cpp for ResourceManager.cpp in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 14:53:05 2014 Nans Marchis-Mouren
// Last update Sat Jun 14 16:45:19 2014 Nans Marchis-Mouren
//

#include "ResourceManager.hh"


ResourceManager::ResourceManager()
{
  _mapMutex = new Mutex();
  _maps = new Map("maps/level");
  _maps->generateRmap();
}

void		ResourceManager::displayMap()
{
  for (unsigned int i = 0; i < _maps->getMap().size(); i += 1)
    displayVector(_maps->getMap()[i]);
}

void		ResourceManager::displayVector(std::vector<std::string> vec)
{
  for (unsigned int i = 0; i < vec.size(); i += 1)
    std::cout << vec[i] << std::endl;
}

const std::vector< std::vector<std::string> >&		ResourceManager::getMap() const
{
  return (_maps->getMap());
}

const std::vector<std::string>&				ResourceManager::getRmap() const
{
  return (_maps->getRmap());
}

void							ResourceManager::generateRmap()
{
  _maps->generateRmap();
}

ResourceManager::~ResourceManager()
{
  delete _mapMutex;
  delete _maps;
}
