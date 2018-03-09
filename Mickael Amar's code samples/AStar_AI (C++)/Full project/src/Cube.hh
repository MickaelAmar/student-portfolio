//
// Cube.hh for GDL in /home/jausse_c/Tp/Bombe
// 
// Made by Jausselme
// Login   <jausse_c@epitech.net>
// 
// Started on  Sat Jun  7 16:25:04 2014 Jausselme
// Last update Sun Jun 15 20:18:52 2014 
//

#ifndef CUBE
# define CUBE

#include "DynEngine.hh"
#include "ResourceManager.hh"
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <SdlContext.hh>
#include "AEntity.hh"

class Cube : public AEntity
{
private:
  
  gdl::Texture  _texture;
  gdl::Geometry _geometry;
  float         _x;
  float         _y;
  float         _z;
  char		_type;

public:

  Cube(int, int, int, char);
  ~Cube();
  bool	initialize();
  void	update(DynEngine *, ResourceManager *);
  void	draw(DynEngine *, gdl::AShader &);
  void	setX(float);
  void	setY(float);
  void	setZ(float);
  float	getX() const;
  float getY() const;
  float getZ() const;
  void	setType(char);
  char	getType() const;
};

#endif
