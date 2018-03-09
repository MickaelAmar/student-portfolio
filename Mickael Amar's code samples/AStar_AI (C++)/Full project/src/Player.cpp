//
// Player.cpp for bomberman in /home/marchi_n/rendu/cpp_bomberman/src
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Thu Jun 12 16:14:08 2014 Nans Marchis-Mouren
// Last update Sun Jun 15 22:22:26 2014 
//

#include "Player.hh"

Player::Player(std::vector<std::string> *curMap, int x, int z)
{
  _x = x;
  _y = 0;
  _z = z;
  _xi = x;
  _yi = z;
  _speed = 10;
  _type = 'P';
  _frame = 0;
  _dir = DOWN;
  _startAnim = false;  
  _prevKey = false;
  _curMap = curMap;
  translate(glm::vec3(x * 6, -2.8, z * 6));
  scale(glm::vec3(0.01, 0.01, 0.01));
}

bool		Player::initialize()
{
  if (_model.load("./lib/assets/marvin.fbx") == false)
    return (false);
  _model.createSubAnim(0, "start", 0, 33);
  _model.createSubAnim(0, "run", 33, 53);
  _model.createSubAnim(0, "end", 53, 115);
  return (true);
}

bool		Player::moveUp(DynEngine *engine, ResourceManager *)
{
  char		type;

  type = (*_curMap)[_yi - 1][_xi];
  if (type != 'W' && type != 'B')
    {
      _z -= (static_cast<float>(engine->getElapsed()) * _speed) / 6;
      rotate(glm::vec3(0, 1, 0), (_dir - UP) * 90);
      translate(glm::vec3(0, 0, -1) * static_cast<float>(engine->getElapsed()) * _speed);
      _dir = UP;
      _yi = static_cast<int>(ceilf(_z));
    }
  return (true);
}

bool		Player::moveDown(DynEngine *engine, ResourceManager *)
{
  char		type;

  type = (*_curMap)[_yi + 1][_xi];
  if (type != 'W' && type != 'B')
    {
      _z += (static_cast<float>(engine->getElapsed()) * _speed) / 6;
      rotate(glm::vec3(0, 1, 0), (_dir - DOWN) * 90);
      translate(glm::vec3(0, 0, 1) * static_cast<float>(engine->getElapsed()) * _speed);
      _dir = DOWN;
      _yi = static_cast<int>(floorf(_z));
    }
  return (true);
}

bool		Player::moveRight(DynEngine *engine, ResourceManager *)
{
  char		type;

  type = (*_curMap)[_yi][_xi + 1];
  if (type != 'W' && type != 'B')
    {
      _x += (static_cast<float>(engine->getElapsed()) * _speed) / 6;
      rotate(glm::vec3(0, 1, 0), (_dir - RIGHT) * 90);
      translate(glm::vec3(1, 0, 0) * static_cast<float>(engine->getElapsed()) * _speed);
      _dir = RIGHT;
      _xi = static_cast<int>(floorf(_x));
    }
  return (true);
}

bool		Player::moveLeft(DynEngine *engine, ResourceManager *)
{
  char		type;

  type = (*_curMap)[_yi][_xi - 1];
  if (type != 'W' && type != 'B')
    {
      _x -= (static_cast<float>(engine->getElapsed()) * _speed) / 6;
      rotate(glm::vec3(0, 1, 0), (_dir - LEFT) * 90);
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(engine->getElapsed()) * _speed);
      _dir = LEFT;
      _xi = static_cast<int>(ceilf(_x));
    }
  return (true);
}

void		Player::update(DynEngine *engine, ResourceManager *res)
{
  //int		i;
  std::map<int, bool (Player::*)(DynEngine *, ResourceManager *)> move;
  int		inputs[4] = { SDLK_UP,
			      SDLK_RIGHT,
			      SDLK_DOWN,
			      SDLK_LEFT };
			     
  move[UP] = &Player::moveUp;
  move[DOWN] = &Player::moveDown;
  move[RIGHT] = &Player::moveRight;
  move[LEFT] = &Player::moveLeft;
  for (int i = 0 ; i < 4 ; i++)
    {
      if ((_prevKey = (engine->getKey(inputs[i]))))
	{
	  _startAnim = true;
	  (this->*move[i])(engine, res);
	  return;
	}
    }
  _dropBomb = engine->getKey(SDLK_SPACE);
  if (_frame == 33)
    _model.setCurrentSubAnim("run", true);
  _frame++;
}

void		Player::draw(DynEngine *engine, gdl::AShader &shader)
{
  _model.draw(shader, getTransformation(), engine->getElapsed());
  _startAnim = false;
}

/*	getter		*/

float	       Player::getX() const
{
  return (_xi);
}

float	       Player::getY() const
{
  return (_y);
}

float	       Player::getZ() const
{
  return (_yi);
}

char		Player::getType() const
{
  return (_type);
}

/*	setter		*/

void		Player::setX(float x)
{
  _x = x;
}

void		Player::setY(float y)
{
  _y = y;
}

void		Player::setZ(float z)
{
  _z = z;
}

void		Player::setType(char type)
{
  _type = type;
}

bool		Player::getDropBomb()
{
  return (_dropBomb ? !(_dropBomb = false) : _dropBomb);
}

Player::~Player()
{

}
