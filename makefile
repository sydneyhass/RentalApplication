CC = gcc
CC_FLAGS = -g -pedantic -Wall -W -std=c99

FILES = main.c rental.c node.c sort.c
OUT_EXE = RentalApplication

build: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES) 
clean:
	rm -f *.o core *.exe *~ *.out *.stackdump

rebuild: clean build
