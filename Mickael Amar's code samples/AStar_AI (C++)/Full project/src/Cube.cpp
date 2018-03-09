//
// Cube.cpp for GDL in /home/jausse_c/Tp/Bombe
// 
// Made by Jausselme
// Login   <jausse_c@epitech.net>
// 
// Started on  Sat Jun  7 38:30:30 3034 Jausselme
// Last update Sun Jun 15 20:54:53 2014 
//

#include <iostream>
#include <AShader.hh>
#include "Cube.hh"
#include "AEntity.hh"

Cube::Cube(int x, int y, int z, char type)
{
  _x = x * 6;
  _y = y * 6;
  _z = z * 6;
  _type = type;
}

bool		Cube::initialize()
{
  if (getType() == 'B')
    {
      if (_texture.load("./lib/assets/marvin.fbm/Box.tga") == false)
	{
	  std::cerr << "Cannot load the cube texture" << std::endl;
	  return false;
	}
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + 3));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + 3));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (3), _z +(-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + (-3)));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + 3));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + (-3)));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + 3));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + (-3)));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    }
  if (getType() == 'W')
    {
      if (_texture.load("./lib/assets/marvin.fbm/Steel.tga") == false)
	{
	  std::cerr << "Cannot load the cube texture" << std::endl;
	  return false;
	}
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + 3));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + 3));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (3), _z +(-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + (-3)));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + 3));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + (-3)));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + 3));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + 3, _z + 3));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
      
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + (-3)));
      _geometry.pushVertex(glm::vec3(_x + 3, _y + (-3), _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + 3));
      _geometry.pushVertex(glm::vec3(_x + (-3), _y + (-3), _z + (-3)));
      
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    }
  _geometry.build();
  
  return (true);
}

Cube::~Cube()
{
}

void	Cube::update(DynEngine *, ResourceManager * /* unused */)
{

}

void	Cube::draw(DynEngine *, gdl::AShader &shader)
{
  _texture.bind();
  _geometry.draw(shader,
		 getTransformation(),
		 GL_QUADS);
}

void	Cube::setX(float x)
{
  this->_x = x;
}

void	Cube::setY(float y)
{
  this->_y = y; 
}

void	Cube::setZ(float z)
{
  this->_z = z;
}

void	Cube::setType(char type)
{
  this->_type = type;
}

char	Cube::getType() const
{
  return (this->_type);
}

float	Cube::getX() const
{
  return _x / 6;
}

float Cube::getY() const
{
  return _y / 6;
}

float Cube::getZ() const
{
  return _z / 6;
}
