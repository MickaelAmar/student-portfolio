//
// IMutex.hh for bomber in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 13:10:18 2014 Nans Marchis-Mouren
// Last update Fri May 30 15:08:44 2014 mickael amar
//

#ifndef IMUTEX_HH_
# define IMUTEX_HH_

# include <pthread.h>

class	IMutex
{
public:

  virtual ~IMutex() {};

  virtual void	lock() = 0;
  virtual void	unlock() = 0;
  virtual bool	trylock() = 0;
};

#endif /* IMUTEX_HH_ */
