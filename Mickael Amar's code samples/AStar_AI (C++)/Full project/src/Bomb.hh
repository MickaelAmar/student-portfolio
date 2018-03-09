//
// Bomb.hh for Bomb in /home/ferrie_j/Desktop/cpp_bomberman/src
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Fri Jun 13 15:35:03 2014 Justin Ferrieu
// Last update Sun Jun 15 22:01:34 2014 
//

#ifndef BOMB_HH_
# define BOMB_HH_

# include <Model.hh>
# include <Texture.hh>
# include "AEntity.hh"

class		Bomb: public AEntity
{
public:
  Bomb(int, int);
  ~Bomb();

  bool		initialize();
  void		update(DynEngine *, ResourceManager *);
  void		draw(DynEngine *, gdl::AShader &);
  void		setX(float);
  void		setY(float);
  void		setZ(float);
  bool		getExplode();

  float		getX() const;
  float		getY() const;
  float		getZ() const;
  char		getType() const;

private:
  gdl::Model	_model;
  gdl::Texture	_texture;
  float		_x;
  float		_y;
  float		_z;
  int		_frame;
  bool		_explode;
  char		_type;
};

#endif
