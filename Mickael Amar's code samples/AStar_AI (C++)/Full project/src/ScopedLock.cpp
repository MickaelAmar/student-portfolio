//
// ScopedLock.cpp for qsd in /home/marchi_n/tp/yolo
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Tue Apr 15 11:30:25 2014 Nans Marchis-Mouren
// Last update Fri May 30 15:31:33 2014 mickael amar
//

#include "ScopedLock.hh"
#include "Mutex.hh"

ScopedLock::ScopedLock(IMutex &mutex) : _mutex(mutex)
{
  _mutex.lock();
}

ScopedLock::~ScopedLock()
{
  _mutex.unlock();
}
