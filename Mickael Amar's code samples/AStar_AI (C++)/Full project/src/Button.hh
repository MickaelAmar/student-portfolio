//
// Button.hh for Button in /home/rose_r/cpp_bomberman/src
// 
// Made by ROSE
// Login   <rose_r@epitech.net>
// 
// Started on  Fri Jun 13 15:53:02 2014 ROSE
// Last update Sun Jun 15 21:50:54 2014 
//

#ifndef __BUTTON_HH__
# define __BUTTON_HH__

# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <SdlContext.hh>
# include "AEntity.hh"

class		Button: public AEntity
{
public:

  Button(float, float, int, int, int);
  ~Button();

  bool		initialize();
  bool		textureSelect();
  void		vertexMaker(int, int);
  void		draw(DynEngine *, gdl::AShader &);
  void		setX(float);
  void		setY(float);
  float		getX() const { return 0; }
  float		getY() const { return 0; }
  float		getZ() const { return 0; }
  char		getType() const { return 0; }

private:

  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_x;
  float		_y;
  int		_weight;
  int		_height;
  int		_id;
};

# endif /* __BUTTON_HH__ */
