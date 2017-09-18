##################################
# Operating Systems- CS 433 Assignment 1
#Kyle Gullicksen
#Benjamin Siegel
###################################
CC = g++                        # use g++ for compiling c++ code or gcc for c code
CFLAGS = -g -Wall               # compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lm                       # linked libraries
LDFLAGS = -L.                   # link flags
PROG = assign1                   # target executable (output)
SRC = main.cpp Processes.cpp ProcessControlBlock.cpp       # .c or .cpp source files.
OBJ = $(SRC:.cpp=.o)    # object files for the target. Add more to this and next lines if there are more than one source files.

all : $(PROG)

$(PROG): $(OBJ)
        $(CC) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)

.cpp.o:
        $(CC) -c $(CFLAGS) $< -o $@

# cleanup
clean:
        /bin/rm -f *.o $(PROG)

# DO NOT DELETE
 
