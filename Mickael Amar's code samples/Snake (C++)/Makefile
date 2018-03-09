##
## Makefile for nibbler in /home/marchi_n/rendu/cpp_nibbler
## 
## Made by Nans Marchis-Mouren
## Login   <marchi_n@epitech.net>
## 
## Started on  Wed Mar 26 09:59:23 2014 Nans Marchis-Mouren
## Last update Sun Jun 15 00:31:22 2014 mickael amar
##

NAME		= nibbler

LIBNAME		= lib_nibbler_sdl.so

SRC		= src/main.cpp \
		src/Game.cpp \
		src/Snake.cpp \
		src/Food.cpp \
		src/GraphicFactory.cpp

LIBSRC		= lib/window_init.cpp \
		lib/sdl_manager.cpp \

OBJ		= $(SRC:.cpp=.o)

LIBOBJ		= $(LIBSRC:.cpp=.o)

RM		= rm -rf

CC		= g++

CXXFLAGS	= -fpic -W -Wall -Wextra -Werror

LDFLAGS		= -shared -lSDL -lSDL_image -ldl

all:		$(NAME) $(LIBNAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -ldl

$(LIBNAME):	$(LIBOBJ)
		$(CC) -o $(LIBNAME) $(LIBOBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)
		$(RM) $(LIBOBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(LIBNAME)

re:		fclean all
