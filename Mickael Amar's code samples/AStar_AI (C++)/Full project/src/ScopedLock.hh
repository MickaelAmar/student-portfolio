//
// ScopedLock.hh for asd in /home/marchi_n/tp/yolo
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Tue Apr 15 11:25:42 2014 Nans Marchis-Mouren
// Last update Fri May 30 15:31:00 2014 mickael amar
//

#ifndef SCOPEDLOCK_HH_
# define SCOPEDLOCK_HH_

# include "IMutex.hh"

class	ScopedLock
{
public:
  ScopedLock(IMutex&);
  ~ScopedLock();

private:

  IMutex	&_mutex;
};

#endif /* SCOPEDLOCK_HH_ */
