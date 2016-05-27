##
## Makefile for  in core
##
## Made by sebastien saletes
## Login   <salete_s@epitech.net>
##
## Started on  Wed Jan 21 03:29:00 2015 sebastien saletes
## Last update Sun May 24 21:12:33 2015 sebastien saletes
##

CXX = clang++

NAME_EXE = sampleLua
SRC_EXE = Binding.cpp \
					main.cpp

OBJ_EXE = $(SRC_EXE:.cpp=.o)

CXXFLAGS += -W -Wall -Wextra -std=c++11
CXXFLAGS += -I./include

all: $(NAME_EXE)

$(NAME_EXE): $(OBJ_EXE)
	$(CXX) -o $(NAME_EXE) $(OBJ_EXE) -L./ -llua -ldl

clean:
	rm -f $(OBJ_EXE)

fclean: clean
	rm -f $(NAME_EXE)

re: fclean all

.PHONY: all clean fclean re
