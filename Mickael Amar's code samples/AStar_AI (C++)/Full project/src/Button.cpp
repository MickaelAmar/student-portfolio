//
// Button.cpp for Button in /home/rose_r/cpp_bomberman/src
// 
// Made by ROSE
// Login   <rose_r@epitech.net>
// 
// Started on  Fri Jun 13 16:08:16 2014 ROSE
// Last update Sun Jun 15 21:33:42 2014 ROSE
//

#include <iostream>
#include <AShader.hh>
#include "Button.hh"
#include "AEntity.hh"

Button::Button(float x, float y, int id, int weight, int height)
{
  _x = x;
  _y = y;
  _id = id;
  _weight = weight;
  _height = height;
}

Button::~Button()
{
}

bool		Button::initialize()
{
  textureSelect();
  vertexMaker(_weight, _height);
  _geometry.build();  
  return (true);
}

bool		Button::textureSelect()
{
  switch (_id)
    {
    case 0:
      if (_texture.load("./lib/assets/marvin.fbm/bmenu2.tga") == false)
        {
	  std::cerr << "Can not load 'bmenu.tga'" << std::endl;
          return false;
        }   
      break;
    case 1:
      if (_texture.load("./lib/assets/marvin.fbm/arrow.tga") == false)
	{
	  std::cerr << "Can not load 'b2.tga'" << std::endl;
	  return false;
	}
      break;
    case 2:
      if (_texture.load("./lib/assets/marvin.fbm/arrow.tga") == false)
	{
	  std::cerr << "Can not load 'b1.tga'" << std::endl;
	  return false;
	}
      break;
    case 3:
      if (_texture.load("./lib/assets/marvin.fbm/play.tga") == false)
        {
	  std::cerr << "Can not load 'play.tga'" << std::endl;
          return false;
        }
      break;
    case 4:
      if (_texture.load("./lib/assets/marvin.fbm/settings.tga") == false)
	{
	  std::cerr << "Can not load 'settings.tga'" << std::endl;
          return false;
        }
      break;
    case 5:
      if (_texture.load("./lib/assets/marvin.fbm/credits.tga") == false)
        {
	  std::cerr << "Can not load 'credits.tga'" << std::endl;
          return false;
        }
      break;
    case 6:
      if (_texture.load("./lib/assets/marvin.fbm/exit.tga") == false)
        {
	  std::cerr << "Can not load 'exit.tga'" << std::endl;
          return false;
        }
      break;
    case 7:
      if (_texture.load("./lib/assets/marvin.fbm/bomb2.tga") == false)
	{
	  std::cerr << "Can not load 'bomb.tga'" << std::endl;
	  return false;
	}
      break;
    case 8:
      if (_texture.load("./lib/assets/marvin.fbm/background.tga") == false)
	{
	  std::cerr << "Can not load 'bmenu.tga'" << std::endl;
	  return false;
	}
    }
  return true;
}

void		Button::vertexMaker(int x, int y)
{
  _geometry.pushVertex(glm::vec3(_x, _y, 0));
  _geometry.pushVertex(glm::vec3(_x + x, _y, 0));
  _geometry.pushVertex(glm::vec3(_x + x, _y + y, 0));
  _geometry.pushVertex(glm::vec3(_x, _y + y, 0));
  
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
}

void		Button::draw(DynEngine *, gdl::AShader &shader)
{
  _texture.bind();
  //  glDisable(GL_DEPTH_TEST);
  glAlphaFunc(GL_GREATER, 0.1f);
  glEnable(GL_ALPHA_TEST);
  _geometry.draw(shader,
		 this->getTransformation(),
		 GL_QUADS);
}

void		Button::setX(float x)
{
  this->_x = x;
}

void		Button::setY(float y)
{
  this->_y = y;
}
