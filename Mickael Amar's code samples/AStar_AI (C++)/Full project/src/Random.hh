//
// Random.hh for bomberman in /home/marchi_n/rendu/cpp_bomberman/src
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Mon Jun  9 14:44:41 2014 Nans Marchis-Mouren
// Last update Mon Jun  9 15:11:10 2014 mickael amar
//

#ifndef RANDOM_HH_
# define RANDOM_HH_

# include <stdlib.h>
# include <time.h>

class		Random
{
public:

  Random();
  ~Random();

  int		randomNb() const;
};
#endif /* RANDOM_HH_ */
