//
// SceneManager.hpp for SceneManager in /home/ferrie_j/Desktop/cpp_bomberman
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Thu Jun  5 16:02:28 2014 Justin Ferrieu
// Last update Sun Jun 15 01:35:52 2014 ROSE
//

#ifndef SCENEMANAGER_HH_
# define SCENEMANAGER_HH_

# include "ResourceManager.hh"
# include "DynEngine.hh"
# include "IScene.hpp"

class			SceneManager
{
public:
  SceneManager();
  ~SceneManager();

  void			setScene(IScene *);
  bool			tick();
  void			render();

private:
  IScene		*_curScene;
};

#endif /* SCENEMANAGER_HH_ */
