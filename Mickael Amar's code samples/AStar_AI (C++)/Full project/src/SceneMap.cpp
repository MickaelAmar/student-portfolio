#include "SceneMap.hh"

SceneMap::SceneMap(DynEngine *engine, ResourceManager *resM)
{
  _engine = engine;
  _resM = resM;
  _p1 = 0;
  _p2 = 0;
  _scene = 0;
}

SceneMap::~SceneMap()
{
}

bool				SceneMap::initialize()
{
  std::vector<std::string>	map;
  glm::mat4			projection;
  glm::mat4			transformation;
  int				x;

  setNmap(0);
  x = getNmap();

  std::cout << "Shader Loading" << std::endl;
  if (!_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  std::cout << "C'est bon!!" << std::endl;

  _curMap = x == 6 ? _resM->getRmap() : _resM->getMap()[x];
  projection = glm::perspective(60.0f, 1880.0f / 1040.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(_curMap[0].size() / 2 * 6,
					 100,
					 _curMap.size() * 6),
			       glm::vec3(_curMap[0].size() / 2 * 6,
					 10,
					 _curMap.size() / 2 * 6),
			       glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  this->drawMap(_curMap);
  this->createPlayer(1, 1);
  return true;
}

bool				SceneMap::tick()
{
  glm::mat4			camera;

  if (_engine->getKey(SDLK_ESCAPE) || _engine->getInput(SDL_QUIT))
    return false;
  _engine->updateClock();
  _engine->updateInputs();
  for (size_t i = 0; i < _ents.size(); i++)
    if (_ents[i])
      _ents[i]->update(_engine, _resM);
  for (size_t i = 0; i < _bombs.size(); i++)
    if (_bombs[i] && _bombs[i]->getExplode())
      {
	this->deleteAround(_bombs[i]->getX(), _bombs[i]->getZ());
	_bombs[i] = 0;
      }
  if (_p1 && _p1->getDropBomb())
    this->createBomb(roundf(_p1->getX()), roundf(_p1->getZ()));
  if (_p1)
    { 
      camera = glm::lookAt(glm::vec3(_curMap[0].size() / 2 * 6 + _p1->getX() / 6,
				   100,
				     _curMap.size() * 6 + _p1->getZ() / 6),
			   glm::vec3(_curMap[0].size() / 2 * 6 + _p1->getX() / 6,
				     10,
				     _curMap.size() / 2 * 6 + _p1->getZ() / 6),
			glm::vec3(0, 1, 0));
      _shader.setUniform("view", camera);
    }
  return true;
}

void				SceneMap::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (size_t i = 0; i < _ents.size(); ++i)
    if (_ents[i])
      _ents[i]->draw(_engine, _shader);
  _engine->flush();
}

void				SceneMap::drawMap(const std::vector<std::string> &map)
{
  int           x;
  int           y;
  int           max_y;
  int           max_x;

  y = 0;
  max_y = map.size();
  max_x = map[0].size();
  std::cout << "max_y(" << max_y << ") map_x(" << max_x << ")" << std::endl;
  while (y < max_y)
    {
      x = 0;
      while (x < max_x)
        {
          this->createCube(x, y, map[y][x], map);
          x++;
        }
      y++;
    }
}

void				SceneMap::deleteAround(int x, int z)
{
  int				cross[9][2] = {{0, 0},
					       {0, 1}, {0, 2},
					       {1, 0}, {2, 0},
					       {0, -1}, {0, -2},
					       {-1, 0}, {-2, 0}};

  (void) x;
  (void) z;
  (void) cross;
  for (unsigned int j = 0; j < _ents.size(); j++)
    {
	for (int i = 0; i < 9; i++)
	  {
	    if (_ents[j]
		&& (_ents[j]->getType() == 'B' || _ents[j]->getType() == 'P')
		&& _ents[j]->getX() + cross[i][0] == x
		&& _ents[j]->getZ() + cross[i][1] == z)
	      {
		std::cout << _ents[j]->getType() << std::endl;
		_curMap[_ents[j]->getZ()][_ents[j]->getX()] = '.';
		if (_ents[j]->getType() == 'P')
		  _p1 = 0;
		_ents[j] = 0;
	      }
	  }
    }
}

bool				SceneMap::createCube(int x, int z, char type, const std::vector<std::string> &map)
{
  AEntity			*cube = new Cube(x, 0, z, type);
  
  if (type == 'W' || type == 'B')
    {
      if (!cube->initialize())
        return false;
      _ents.push_back(cube);
    }
  else if (type == 'p')
    {
      AEntity			*plane = new Plane(x, z, map);
      if (!plane->initialize())
        return false;
      _ents.push_back(plane);
    }
  return true;
}

bool				SceneMap::createPlayer(int x, int z)
{
  Player			*player = new Player(&_curMap, x, z);

  if (!player->initialize())
    return (false);
  _ents.push_back(player);
  if (!_p1)
    _p1 = player;
  else
    _p2 = player;
  return (true);
}

bool				SceneMap::createBomb(int x, int z)
{
  Bomb				*bomb = new Bomb(x, z);

  if (!bomb->initialize())
    return false;
  _ents.push_back(bomb);
  _bombs.push_back(bomb);
  return true;
}

int				SceneMap::getNmap() const
{
  return (_nMap);
}

void				SceneMap::setNmap(int x)
{
  this->_nMap = x;
}

IScene*				SceneMap::getScene() const
{
  return _scene;
}
