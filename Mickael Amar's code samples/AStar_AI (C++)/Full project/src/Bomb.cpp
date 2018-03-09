//
// Bomb.cpp for Bomb in /home/ferrie_j/Desktop/cpp_bomberman/src
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Fri Jun 13 15:45:36 2014 Justin Ferrieu
// Last update Sun Jun 15 22:03:31 2014 
//

#include <iostream>
#include "Bomb.hh"

Bomb::Bomb(int x, int z)
{
  _x = x;
  _y = 0;
  _z = z;
  _frame = 0;
  _type = 'X';
  this->translate(glm::vec3(_x * 6, -2.8, _z * 6));
  this->scale(glm::vec3(0.01, 0.01, 0.01));
}

Bomb::~Bomb()
{
  
}

bool		Bomb::initialize()
{
  if (!_model.load("./lib/assets/bomb.fbx"))
    {
      std::cerr << "Cannot load the bomb model" << std::endl;
      return false;
    }
  return true;
}

void		Bomb::update(DynEngine *, ResourceManager *)
{
  _explode = _frame++ > 200;
}

void		Bomb::draw(DynEngine *engine, gdl::AShader &shader)
{
  _model.draw(shader, this->getTransformation(), engine->getElapsed());
  _frame++;
}

void		Bomb::setX(float x)
{
  this->_x = x;
}

void		Bomb::setY(float y)
{
  this->_y = y;
}

void		Bomb::setZ(float z)
{
  this->_z = z;
}

bool		Bomb::getExplode()
{
  return _explode ? !(_explode = false) : false;
}

float		Bomb::getX() const
{
  return _x;
}

float		Bomb::getY() const
{
  return _y;
}

float		Bomb::getZ() const
{
  return _z;
}

char		Bomb::getType() const
{
  return _type;
}
