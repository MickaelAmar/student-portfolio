//
// Snake.hh for Snake in /home/mika/cpp_nibbler/src
// 
// Made by mickael amar
// Login   <amar_e@epitech.net>
// 
// Started on  Sat Apr  5 15:10:28 2014 mickael amar
// Last update Sun Apr  6 18:34:54 2014 Nans Marchis-Mouren
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

# include <vector>
# include <map>
# include "Food.hh"
# include "nibbler.h"

class		Food;

class		Snake
{
public:
  enum		eDirection
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    };

  enum		eOrientation
    {
      VERTICAL,
      HORIZONTAL
    };

private:
  std::vector<t_snake>		_snake;
  eDirection			_direction;
  eOrientation			_orientation;
  int				_width;
  int				_height;
  Food				*_food;
  bool				_ate;
  t_snake			_tail;

public:
  Snake(int, int);
  ~Snake();

  const std::vector<t_snake>&	getSnake() const;
  void				createSnake(eSnakeBody, int, int);

  void				setFood(Food*);

  void				moveSnake(int, int, eDirection, eOrientation);
  void				left();
  void				right();
  void				moveUp();
  void				moveDown();
  void				moveLeft();
  void				moveRight();
  void				displaySnake() const;
  void				checkFood();
  void				checkWall() const;
  void				checkSnake() const;
  int				getTailPos() const;
  void				setTail(t_snake);
  void				extendSnake();
  void				autoMove();
};

#endif /* !SNAKE_HH_ */
