//
// Plane.cpp for GDL in /home/jausse_c/Tp/Bombe
// 
// Made by Jausselme
// Login   <jausse_c@epitech.net>
// 
// Started on  Thu Jun 12 12:27:24 2014 Jausselme
// Last update Sun Jun 15 21:45:28 2014 
//

#include <iostream>
#include <AShader.hh>
#include "Plane.hh"
#include "AEntity.hh"

Plane::Plane(int x, int z, const std::vector<std::string> &map)
{
  _x = x;
  _y = 0;
  _z = z;
  _maxX = map[0].size();
  _maxZ = map.size();
}

bool  Plane::initialize()
{
  if (_texture.load("./lib/assets/marvin.fbm/Floor.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  
  _geometry.pushVertex(glm::vec3(_maxX / 2 * 6 + 45, -3, _maxZ / 2 * 6 - 39));
  _geometry.pushVertex(glm::vec3(_maxX / 2 * 6 + 45, -3, _maxZ / 2 * 6 + 39));
  _geometry.pushVertex(glm::vec3(_maxX / 2 * 6 - 45, -3, _maxZ / 2 * 6 + 39));
  _geometry.pushVertex(glm::vec3(_maxX / 2 * 6 - 45, -3, _maxZ / 2 * 6 - 39));
  
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.build();
  
  return (true);
}

void    Plane::update(DynEngine *, ResourceManager * /* unused */)
{
  
}

void    Plane::draw(DynEngine *, gdl::AShader &shader)
{
  _texture.bind();
  _geometry.draw(shader, 
		 getTransformation(),
		 GL_QUADS);
}

void    Plane::setX(int x)
{
  this->_x = x;
}

void    Plane::setY(int y)
{
  this->_y = y;
}

void	Plane::setZ(int z)
{
  this->_z = z;
}

float	Plane::getX() const
{
  return _x;
}

float	Plane::getY() const
{
  return _y;
}

float	Plane::getZ() const
{
  return _z;
}

char	Plane::getType() const
{
  return 0;
}
