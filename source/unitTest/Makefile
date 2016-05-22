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

NAME_EXE = unitTest
SRC_EXE = main.cpp \
					tuto.cpp

OBJ_EXE = $(SRC_EXE:.cpp=.o)

LIBDIR		+= -L../../lib/google_test/lib -lgtest
LIBDIR 		+= -Wl,-rpath,../../lib/google_test/lib
CXXFLAGS 	+= -W -Wall -Wextra  -std=c++11
CXXFLAGS 	+= -I../../lib/google_test/include/gtest
CXXFLAGS 	+= -I../../lib/google_test/include



all: $(NAME_EXE)

$(NAME_EXE): $(OBJ_EXE)
	$(CXX) -o $(NAME_EXE) $(OBJ_EXE) $(LIBDIR) $(LDFLAGS)

clean:
	rm -f $(OBJ_EXE)

fclean: clean
	rm -f $(NAME_EXE)

re: fclean all

.PHONY: all clean fclean re
