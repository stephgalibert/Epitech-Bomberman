##
## Makefile for  in core
##
## Made by sebastien saletes
## Login   <salete_s@epitech.net>
##
## Started on  Wed Jan 21 03:29:00 2015 sebastien saletes
## Last update Sun May 24 21:12:33 2015 sebastien saletes
##

CXX = g++

NAME_EXE = testSample
SRC_EXE = main.cpp

OBJ_EXE = $(SRC_EXE:.cpp=.o)

LDFLAGS= -L../../../lib/google_test/lib -lgtest -lpthread
CXXFLAGS += -W -Wall -Wextra  -std=c++11

CXXFLAGS += -I../../../lib/google_test/include
CXXFLAGS += -I../../../lib/google_test/include/gtest

all: $(NAME_EXE)

$(NAME_EXE): $(OBJ_EXE)
	$(CXX) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)

clean:
	rm -f $(OBJ_EXE)

fclean: clean
	rm -f $(NAME_EXE)

re: fclean all

.PHONY: all clean fclean re
