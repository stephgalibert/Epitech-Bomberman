# Makefile for Irrlicht Examples
# It's usually sufficient to change just the target name and source file list
# and be sure that CXX is set to a valid compiler
Target = ./bin/bomberman
Directory = ./source/
Sources += $(Directory)main.cpp
Sources += $(Directory)Application.cpp
Sources += $(Directory)Game.cpp
Sources += $(Directory)Board.cpp
Sources += $(Directory)powerups/PowerUPs.cpp
Sources += $(Directory)powerups/SpeedUPPowerUP.cpp
Sources += $(Directory)effects/SpeedUPEffect.cpp
Sources += $(Directory)players/HumanPlayer.cpp
Sources += $(Directory)blocks/IndestructibleBlock.cpp
Sources += $(Directory)BombManager.cpp
Sources += $(Directory)bombs/ExplodingBomb.cpp
Sources += $(Directory)InputListener.cpp
Sources += $(Directory)Irrlicht.cpp
Sources += $(Directory)utils/Chronometer.cpp
Sources += $(Directory)utils/Generator.cpp

Objects = $(Sources:.cpp=.o)

# general compiler settings
#CPPFLAGS = -I../include -I/usr/X11R6/include
CXXFLAGS += -isystem ./lib/include -isystem /usr/X11R6/include
CXXFLAGS += -I./source/
CXXFLAGS += -I./source/powerups/
CXXFLAGS += -I./source/utils/
CXXFLAGS += -I./source/bombs/
CXXFLAGS += -I./source/effects/
CXXFLAGS += -I./source/players/
CXXFLAGS += -I./source/blocks/
CXXFLAGS += -O3 -ffast-math -std=c++11
CXXFLAGS += -Wall -Werror -Wextra

#default target is Linux
all: all_linux

ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif

# target specific settings
all_linux: LDFLAGS = -L/usr/X11R6/lib$(LIBSELECT) -L./lib/lib/Linux -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor
all_linux clean_linux: SYSTEM=Linux
all_win32: LDFLAGS = -L./lib/lib/Win32-gcc -lIrrlicht -lopengl32 -lm
all_win32: CPPFLAGS += -D__GNUWIN32__ -D_WIN32 -DWIN32 -D_WINDOWS -D_MBCS -D_USRDLL
all_win32 clean_win32: SYSTEM=Win32-gcc
all_win32 clean_win32: SUF=.exe
# name of the binary - only valid for targets which set SYSTEM
#DESTPATH = ../../bin/$(SYSTEM)/$(Target)$(SUF)
DESTPATH = ./$(Target)$(SUF)

all_linux all_win32: 	$(DESTPATH)

$(DESTPATH):		$(Objects)
			$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Objects) -o $(DESTPATH) $(LDFLAGS)

clean: #clean_linux clean_win32
			rm -f $(Objects)

#clean_linux clean_win32:
#@$(RM) $(DESTPATH)

re: 			fclean all

fclean: 		clean_win32 clean
			rm -f $(DESTPATH)

.PHONY: all all_win32 clean clean_linux clean_win32
