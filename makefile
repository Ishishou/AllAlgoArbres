CC = clang
CFLAGS = -Wall -pedantic -std=c17 -Iinclude
SRC = main.c src/AB.c src/utils.c 
EXEC = run

all :
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) 
