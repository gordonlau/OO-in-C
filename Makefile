CC=gcc

listmake: arraylist.c linkedlist.c main.c 
	$(CC) -o main main.c linkedlist.c arraylist.c  -I.
