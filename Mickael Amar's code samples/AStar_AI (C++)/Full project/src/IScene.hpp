//
// IScene.hpp for IScene in /home/ferrie_j/Desktop/cpp_bomberman
// 
// Made by Justin Ferrieu
// Login   <ferrie_j@epitech.net>
// 
// Started on  Thu Jun  5 15:59:53 2014 Justin Ferrieu
// Last update Sun Jun 15 02:02:03 2014 ROSE
//

#ifndef ISCENE_HPP
# define ISCENE_HPP

# include "ResourceManager.hh"

class			IScene
{
public:
  virtual		~IScene() {}

  virtual bool		initialize() = 0;
  virtual bool		tick() = 0;
  virtual void		render() = 0;
  virtual IScene	*getScene() const = 0;
};

#endif /* ISCENE_HPP */
