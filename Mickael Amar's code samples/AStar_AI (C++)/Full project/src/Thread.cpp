//
// Thread.cpp for bomberman in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 13:13:55 2014 Nans Marchis-Mouren
// Last update Wed Jun  4 16:43:41 2014 Nans Marchis-Mouren
//

#include "Thread.hh"

Thread::Thread(Routine routine, void *arg)
{
  _routine = routine;
  _arg = arg;
}

int	Thread::start()
{
  return (pthread_create(&_thread, NULL, _routine, _arg));
}

int	Thread::join() const
{
  return (pthread_join(_thread, NULL));
}

Thread::~Thread()
{
  pthread_exit(0);
}
