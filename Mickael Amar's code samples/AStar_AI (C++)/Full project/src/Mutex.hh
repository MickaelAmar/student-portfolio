//
// Mutex.hh for bomberman in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 13:10:49 2014 Nans Marchis-Mouren
// Last update Wed May 28 13:10:50 2014 Nans Marchis-Mouren
//

#ifndef MUTEX_HH_
# define MUTEX_HH_

# include <pthread.h>
# include "IMutex.hh"

class	Mutex : public IMutex
{
public:

  Mutex();
  ~Mutex();

  void	lock();
  void	unlock();
  bool	trylock();

private:

  pthread_mutex_t	_mutex;
};

#endif /* MUTEX_HH_ */
