//
// Mutex.cpp for bomberman in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 13:10:35 2014 Nans Marchis-Mouren
// Last update Wed May 28 13:10:36 2014 Nans Marchis-Mouren
//

#include "Mutex.hh"

Mutex::Mutex()
{
  pthread_mutex_init(&_mutex, NULL);
}

void	Mutex::lock()
{
  pthread_mutex_lock(&_mutex);
}

void	Mutex::unlock()
{
  pthread_mutex_unlock(&_mutex);
}

bool	Mutex::trylock()
{
  return (pthread_mutex_trylock(&_mutex));
}

Mutex::~Mutex()
{
  pthread_mutex_destroy(&_mutex);
}
