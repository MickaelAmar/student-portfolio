//
// Player.hh for bomberman in /home/marchi_n/rendu/cpp_bomberman/src
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Thu Jun 12 16:06:51 2014 Nans Marchis-Mouren
// Last update Sun Jun 15 22:21:37 2014 
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <Model.hh>
# include <map>
# include <cstdlib>
# include <cmath>
# include "AEntity.hh"

class		Player : public AEntity
{
public:
  Player(std::vector<std::string> *, int, int);
  ~Player();

  float		getX() const;
  float		getY() const;
  float		getZ() const;
  char		getType() const;

  void		setX(float);
  void		setY(float);
  void		setZ(float);
  void		setType(char);

  bool		initialize();
  void		update(DynEngine *, ResourceManager *);
  void		draw(DynEngine *, gdl::AShader &);

  bool		moveUp(DynEngine *, ResourceManager *);
  bool		moveDown(DynEngine *, ResourceManager *);
  bool		moveRight(DynEngine *, ResourceManager *);
  bool		moveLeft(DynEngine *, ResourceManager *);

  bool		getDropBomb();

private:
  
enum		ePos
  {
    UP,
    RIGHT,
    DOWN,
    LEFT
  };  
  ePos		_dir;
  gdl::Model	_model;
  float		_speed;
  float		_x;
  float		_y;
  float		_z;
  bool		_startAnim;
  int		_frame;
  char		_type;
  int		_xi;
  int		_yi;
  bool		_dropBomb;
  bool		_prevKey;
  std::vector<std::string> *_curMap;
};

#endif /* PLAYER_HH_ */
