//
// DynEngine.cpp for DynEngine in /home/ferrie_j/Desktop/cpp_bomberman
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Tue Jun 10 13:16:41 2014 Justin Ferrieu
// Last update Sun Jun 15 21:54:31 2014 
//

#include "SceneMap.hh"
#include "DynEngine.hh"

DynEngine::DynEngine()
{
}

DynEngine::~DynEngine()
{
  _context.stop();
}

bool		DynEngine::initialize()
{
  bool		ret;

  ret = _context.start(1880, 1040, "My bomberman!");
  glEnable(GL_DEPTH_TEST);
  return ret;
}

void		DynEngine::updateClock()
{
  _context.updateClock(_clock);
}

void		DynEngine::updateInputs()
{
  _context.updateInputs(_input);
}

void		DynEngine::flush() const
{
  _context.flush();
}

bool		DynEngine::getInput(int input)
{
  return _input.getInput(input);
}

bool		DynEngine::getKey(int input)
{
  return _input.getKey(input);
}

bool            DynEngine::getKeyDown(int input)
{
  if (SDL_PollEvent(&_event))
    {
      if (_event.type == SDL_KEYDOWN)
	return (_event.key.keysym.sym == input);
    }
  return _input.getKey(input);
}

bool            DynEngine::getKeyUp(int input)
{
  if (SDL_PollEvent(&_event))
    {
      if (_event.type == SDL_KEYUP)
        return (_event.key.keysym.sym == input);
    }
  return _input.getKey(input);
}

double		DynEngine::getElapsed() const
{
  return _clock.getElapsed();
}
