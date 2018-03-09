//
// Random.cpp for bomberman in /home/marchi_n/rendu/cpp_bomberman/src
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Mon Jun  9 14:53:38 2014 Nans Marchis-Mouren
// Last update Mon Jun  9 15:11:01 2014 mickael amar
//

#include "Random.hh"

Random::Random()
{
  srand(time(0));
}

int	Random::randomNb() const
{
  return (rand());
}

Random::~Random()
{
}
