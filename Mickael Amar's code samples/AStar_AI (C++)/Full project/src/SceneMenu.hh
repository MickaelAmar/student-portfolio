//
// SceneMenu.hh for SceneMenu in /home/rose_r/cpp_bomberman/src
// 
// Made by ROSE
// Login   <rose_r@epitech.net>
// 
// Started on  Fri Jun 13 15:16:49 2014 ROSE
// Last update Sun Jun 15 01:55:09 2014 ROSE
//

#ifndef SCENEMENU_HH
# define SCENEMENU_HH

# include <vector>
# include <string>
# include <SdlContext.hh>
# include <BasicShader.hh>
# include "ResourceManager.hh"
# include "IScene.hpp"
# include "DynEngine.hh"
# include "AEntity.hh"
# include "Button.hh"
# include "SceneMap.hh"

class				SceneMenu: public IScene
{
public:
  SceneMenu(DynEngine *, ResourceManager *);
  ~SceneMenu();

  bool				initialize();
  bool				tick();
  void				render();
  IScene			*getScene() const;

private:

  bool				drawMenu();
  void				playScene();

  DynEngine			*_engine;
  ResourceManager		*_resM;
  IScene			*_nextScene;
  gdl::BasicShader		_shader;
  std::vector<AEntity *>	_ents;
  int				_selection;
};

# endif /* SCENEMENU_HH */
