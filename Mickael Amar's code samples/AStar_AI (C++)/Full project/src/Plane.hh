//
// Plane.hh for GDL in /home/jausse_c/rendu/cpp_bomberman/graph
// 
// Made by Jausselme
// Login   <jausse_c@epitech.net>
// 
// Started on  Thu Jun 12 16:13:32 2014 Jausselme
// Last update Sun Jun 15 20:30:53 2014 
//

#ifndef PLANE
# define PLANE

#include "DynEngine.hh"
#include "ResourceManager.hh"
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <SdlContext.hh>
#include "AEntity.hh"

class Plane : public AEntity
{
private:

  gdl::Texture			_texture;
  gdl::Geometry			_geometry;
  int				_x;
  int				_y;
  int				_z;
  int				_maxX;
  int				_maxZ;
public:
  
  Plane(int, int, const std::vector<std::string> &);
  ~Plane() {};
  bool	initialize();
  void	update(DynEngine *, ResourceManager *);
  void	draw(DynEngine *, gdl::AShader &);
  void	setX(int);
  void	setY(int);
  void	setZ(int);
  float getX() const;
  float getY() const;
  float getZ() const;
  char	getType() const;
};

#endif
