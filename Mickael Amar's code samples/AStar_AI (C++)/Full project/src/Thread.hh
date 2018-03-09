//
// Thread.hh for bomberman in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 13:12:03 2014 Nans Marchis-Mouren
// Last update Wed Jun  4 16:43:17 2014 Nans Marchis-Mouren
//

#ifndef THREAD_HH_
# define THREAD_HH_

# include <pthread.h>
# include "IThread.hh"

class			Thread : public IThread
{
public:

  typedef void 	*(*Routine)(void*);

  Thread(Routine, void*);
  ~Thread();

  int			start();
  int			join() const;

private:

  void			*_arg;
  pthread_t		_thread;
  Routine		_routine;

};

#endif /* THREAD_HH_ */
