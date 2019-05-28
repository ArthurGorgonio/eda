
# Name of the project
PROJ_NAME=sort

# .c files
C_SOURCE=$(wildcard *.c)

# .h files
H_SOURCE=$(wildcard *.h)

# Object files
OBJ=$(C_SOURCE:.c=.o)

# Compiler
CC=gcc

# Flags
CC_FLAGS=-c		\
	 -W		\
	 -Wall		\
	 -ansi		\
	 -pedantic

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@echo "Building $@"
	$(CC) -o $@ $^
	@echo "Finish the build: $@

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(H_SOURCE)
	$(CC) $< $(CC_FLAGS) -o $@

clean:
	rm -rf *.o $(PROJ_NAME)
