//
// DynEngine.hpp for DynEngine in /home/ferrie_j/Desktop/cpp_bomberman
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Tue Jun 10 13:14:15 2014 Justin Ferrieu
// Last update Sun Jun 15 01:36:24 2014 ROSE
//

#ifndef DYNENGINE_HH_
# define DYNENGINE_HH_

# include <SdlContext.hh>
# include <Input.hh>
# include <SDL/SDL.h>

class			DynEngine
{
public:
  DynEngine();
  ~DynEngine();

  bool			initialize();
  void			updateClock();
  void			updateInputs();
  void			flush() const;
  bool			getInput(int);
  bool			getKey(int);
  bool			getKeyDown(int);
  bool			getKeyUp(int);
  double		getElapsed() const;

private:
  SDL_Event		_event;
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
};

#endif /* DYNENGINE_HPP_ */
