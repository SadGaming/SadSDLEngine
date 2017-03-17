#inclue these files
OBJS = Start.cpp classes/*

#output exec
OBJ_NAME = game

#compiler
CC = g++

#compiler flags
COMPILER_FLAGS = -w

#libraries linked
LINKER_FLAGS = -lSDL2 -lSDL2_image

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
