##
## Makefile for qsd in /home/marchi_n/bomber
## 
## Made by Nans Marchis-Mouren
## Login   <marchi_n@epitech.net>
## 
## Started on  Wed May 28 14:10:42 2014 Nans Marchis-Mouren
## Last update Sun Jun 15 21:45:59 2014 
##

NAME		= bomberman

SRCDIR		= src/

SRC		= $(SRCDIR)main.cpp \
		$(SRCDIR)Mutex.cpp \
		$(SRCDIR)Thread.cpp \
		$(SRCDIR)ResourceManager.cpp \
		$(SRCDIR)SceneManager.cpp \
		$(SRCDIR)SceneMap.cpp \
		$(SRCDIR)SceneMenu.cpp \
		$(SRCDIR)AEntity.cpp \
		$(SRCDIR)Core.cpp \
		$(SRCDIR)Map.cpp \
		$(SRCDIR)Random.cpp \
		$(SRCDIR)Cube.cpp \
		$(SRCDIR)Button.cpp \
		$(SRCDIR)Plane.cpp \
		$(SRCDIR)DynEngine.cpp \
		$(SRCDIR)Player.cpp \
		$(SRCDIR)Bomb.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS        = -fpic -W -Wall -Werror -Wextra -I./lib/includes/ -I. -g3

LDFLAGS         = -Llib/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

all:		$(NAME) $(LIBNAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
