#
# Makefile for cpp_plazza in /home/salete_s/rendu/cpp_plazza
#
# Made by salete_s
# Login   <salete_s@epitech.net>
#
# Started on  Mon Apr 04 00:36:26 2016 salete_s
## Last update Sun Apr 24 18:33:19 2016 avelin_j
#

CXX=	clang++

RM=	rm -f

NAME= plazza

SRCS=		main.cpp \
				ThreadPool.cpp

OBJS=	$(SRCS:.cpp=.o)

CXXFLAGS += -W -Wall -Wextra -std=c++11 -g

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) -lpthread

re: 		fclean all

clean:
		$(RM) $(OBJS) $(OBJS_UI)

fclean: 	clean
		$(RM) $(NAME)
.PHONY: all clean fclean re
