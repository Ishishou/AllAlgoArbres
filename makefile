CC = clang
CFLAGS = -Wall -pedantic -std=c17 -Iinclude
SRC = main.c src/AB.c src/utils.c src/AL.c src/Tas.c
EXEC = run

all :
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) 
