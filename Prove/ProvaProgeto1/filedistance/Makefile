CC = gcc

filedistance: main.o levenshtein.o time.o
	$(CC) -o filedistance main.o levenshtein.o time.o

main.o : main.c time.h levenshtein.h
	$(CC) -c main.c
levenshtein.o : levenshtein.c levenshtein.h
	$(CC) levenshtein.c -o levenshtein.o
time.o : time.c time.h
	$(CC) time.c -o time.o