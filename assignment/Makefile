# Makefile for EE554 Software Library

# Where are the include and source files?
INCLUDE = ./
SRC = ./

# The location of the maths library goes in here
LIBM_DIR=/usr/lib

# For use with GNU's gcc
LIBS = -lm
LINKFLAGS = -g -L$(LIBM_DIR)
CFLAGS = -g -c -Wall -I$(INCLUDE)
CC = gcc
EXE = 
OBJ = .o 

# List all the object files to be linked here
EXAMPLE_OBJS = example$(OBJ) ee554$(OBJ) ee554_lib$(OBJ) transform$(OBJ)
EXAMPLE2_OBJS = example2$(OBJ) ee554$(OBJ) ee554_lib$(OBJ)

# Tell make how to produce the executable from the object files
all: example$(EXE) example2$(EXE)

example$(EXE) : $(EXAMPLE_OBJS)
	$(CC) $(LINKFLAGS) -o example$(EXE) $(EXAMPLE_OBJS) $(LIBS)

example2$(EXE) : $(EXAMPLE2_OBJS)
	$(CC) $(LINKFLAGS) -o example2$(EXE) $(EXAMPLE2_OBJS) $(LIBS)

# The dependencies list for the object files
example$(OBJ) : $(INCLUDE)ee554.h $(INCLUDE)ee554_lib.h $(SRC)example.c
		$(CC) $(CFLAGS) $(SRC)example.c

example2$(OBJ) : $(INCLUDE)ee554.h $(INCLUDE)ee554_lib.h $(SRC)example2.c
		$(CC) $(CFLAGS) $(SRC)example2.c

ee554$(OBJ) : $(INCLUDE)ee554.h $(INCLUDE)ee554_lib.h $(SRC)ee554.c
		$(CC) $(CFLAGS) $(SRC)ee554.c

ee554_lib$(OBJ) : $(INCLUDE)ee554_lib.h $(SRC)ee554_lib.c
		$(CC) $(CFLAGS) $(SRC)ee554_lib.c



# "make clean" compiles everything
clean:
	rm -f core $(EXAMPLE_OBJS) $(EXAMPLE2_OBJS) *~ *exe


