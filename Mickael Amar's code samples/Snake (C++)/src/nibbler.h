/*
** nibbler.h for nibbler in /home/marchi_n/rendu/cpp_nibbler/src
** 
** Made by Nans Marchis-Mouren
** Login   <marchi_n@epitech.net>
** 
** Started on  Sun Apr  6 19:02:11 2014 Nans Marchis-Mouren
** Last update Sun Apr  6 19:02:12 2014 Nans Marchis-Mouren
*/


#ifndef NIBBLER_H_
# define NIBBLER_H_

enum		eSnakeBody
  {
    HEAD,
    BODY,
    TAIL
  };

enum		eEvent
  {
    LEFT,
    RIGHT,
    ESCAPE,
    EXIT,
    NONE
  };

typedef struct	s_snake
{
  eSnakeBody	part;
  int		x;
  int		y;
}		t_snake;

#endif /* !NIBBLER_H_ */
