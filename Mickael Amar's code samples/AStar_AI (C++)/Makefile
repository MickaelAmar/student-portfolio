##
## Makefile for Makefile in /home/amar_e/AStar_AI
## 
## Made by amar_e
## Login   <amar_e@epitech.net>
## 
## Started on  Fri Jun 13 18:06:37 2014 amar_e
## Last update Sun Jun 15 19:03:55 2014 mickael amar
##

CC=		g++

RM=		rm -fr

SRC=		Intelligence.cpp\
		main.cpp

NAME=		AStar

OBJ=		$(SRC:.cpp=.o)

$(NAME):	all

all:		$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(NAME)

fclean:		clean
		$(RM) $(OBJ)

re:		fclean all
