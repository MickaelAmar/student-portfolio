//
// Food.hh for nibbler in /home/marchi_n/rendu/cpp_nibbler/src
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Sat Apr  5 13:17:28 2014 Nans Marchis-Mouren
// Last update Sun Apr  6 00:56:56 2014 mickael amar
//

#ifndef FOOD_HH_
# define FOOD_HH_

# include "Snake.hh"

class		Snake;

class		Food
{
public:

  Food(int, int);
  ~Food();

  void		putFood(const Snake*);
  int		getX() const;
  int		getY() const;

private:

  int		_x;
  int		_y;
  int		_width;
  int		_height;

};

#endif /* FOOD_HH_ */
