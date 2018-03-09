//
// Core.hh for bomberman in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 14:28:01 2014 Nans Marchis-Mouren
// Last update Fri Jun 13 14:15:50 2014 Justin Ferrieu
//

#ifndef CORE_HH_
# define CORE_HH_

# include <SdlContext.hh>
# include "Game.hh"
# include "DynEngine.hh"
# include "ResourceManager.hh"
# include "SceneManager.hh"

class			Core: public gdl::Game
{
public:
  Core(DynEngine*,
       ResourceManager*,
       SceneManager*);
  ~Core();

  bool			initialize();
  int			start();
  bool			update();
  void			render();
  void			draw();

private:
  DynEngine		*_engine;
  ResourceManager	*_resManager;
  SceneManager		*_sceManager;
};

#endif /* CORE_HH_ */
