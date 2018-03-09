//
// IThread.hh for bomber in /home/marchi_n/rendu/cpp_bomberman
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Mon Jun  2 15:03:43 2014 Nans Marchis-Mouren
// Last update Mon Jun  2 15:05:52 2014 Nans Marchis-Mouren
//

#ifndef ITHREAD_HH_
# define ITHREAD_HH_

class	IThread
{
public:

  virtual ~IThread() {};

  virtual int	start() = 0;
  virtual int	join() const = 0;
};

#endif /* ITHREAD_HH_ */
