//
// SceneMap.hh for SceneMap in /home/ferrie_j/Desktop/cpp_bomberman/src
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Tue Jun 10 13:55:14 2014 Justin Ferrieu
// Last update Sun Jun 15 21:43:55 2014 
//

#ifndef SCENEMAP_HH
# define SCENEMAP_HH

# include <vector>
# include <string>
# include <SdlContext.hh>
# include <BasicShader.hh>
# include "ResourceManager.hh"
# include "IScene.hpp"
# include "DynEngine.hh"
# include "AEntity.hh"
# include "Cube.hh"
# include "Plane.hh"
# include "Player.hh"
# include "Bomb.hh"

class				SceneMap: public IScene
{
public:
  SceneMap(DynEngine *, ResourceManager *);
  ~SceneMap();

  bool				initialize();
  bool				tick();
  void				render();

private:
  bool				createCube(int, int, char, const std::vector<std::string> &);
  bool				createPlayer(int, int);
  bool				createBomb(int, int);
  void				drawMap(const std::vector<std::string> &map);
  int				getNmap() const;
  void				setNmap(int);

  void				deleteAround(int, int);
  IScene			*getScene() const;

  DynEngine			*_engine;
  ResourceManager		*_resM;
  Player			*_p1;
  Player			*_p2;
  IScene			*_scene;
  gdl::BasicShader		_shader;
  std::vector<AEntity *>	_ents;
  std::vector<Bomb *>		_bombs;
  std::vector<std::string>	_curMap;
  int				_nMap;
};

#endif /* SCENEMAP_HH */
