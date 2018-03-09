//
// AEntity.hpp for AEntity in /home/ferrie_j/Desktop/cpp_bomberman
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Thu Jun  5 16:27:17 2014 Justin Ferrieu
// Last update Sun Jun 15 20:28:15 2014 
//

#ifndef AENTITY_HPP_
# define AENTITY_HPP_

# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <AShader.hh>
# include <Game.hh>
# include <Clock.hh>
# include <Input.hh>
# include "DynEngine.hh"
# include "ResourceManager.hh"

class		GraphicsManager;

class           AEntity
{
public:
  AEntity();
  virtual       ~AEntity() {};

  virtual bool	initialize() = 0;
  virtual float getX() const = 0;
  virtual float getY() const = 0;
  virtual float getZ() const = 0;
  virtual char	getType() const = 0;
  virtual void  setX(float) {};
  virtual void  setY(float) {};
  virtual void  setZ(float) {};
  virtual void  setType(char) {};
  virtual void  update(DynEngine *, ResourceManager *) {};
  virtual void  draw(DynEngine *, gdl::AShader &) = 0;

  void		setPosition(glm::vec3 const &);
  void          translate(glm::vec3 const &);
  void          rotate(glm::vec3 const &, float);
  void          scale(glm::vec3 const &);
  glm::mat4     getTransformation();

protected:
  glm::vec3     _position;
  glm::vec3     _rotation;
  glm::vec3     _scale;
};

#endif /* AENTITY_HPP_ */
