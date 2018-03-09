//
// AEntity.cpp for AEntity in /home/ferrie_j/Desktop/cpp_bomberman
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Thu Jun  5 16:34:36 2014 Justin Ferrieu
// Last update Sun Jun 15 01:47:45 2014 Nans Marchis-Mouren
//

#include "AEntity.hh"

AEntity::AEntity()
  : _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{
}

void		AEntity::setPosition(glm::vec3 const &v)
{
  _position -= _position;
  translate(v);
}

void            AEntity::translate(glm::vec3 const &v)
{
  _position += v;
}

void            AEntity::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void            AEntity::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4       AEntity::getTransformation()
{
  glm::mat4     transform(1);

  transform = glm::translate(transform, _position);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  //transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return (transform);
}
