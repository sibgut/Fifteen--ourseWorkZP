# Specify compiler
CC=gcc
 
# Specify linker
LINK=gcc
 
# Build all target
.PHONY : all
all : app

# Compile the source files into object files
fifteen.o : fifteen.cpp
$(CC) -c fifteen.cpp -o fifteen.o
 
# Clean target
.PHONY : clean
clean :
rm fifteen.o app
