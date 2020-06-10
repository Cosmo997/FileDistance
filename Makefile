CC = gcc
OBJ = main.o file_distance.o leven.o timer.o
EXEC = filedistance

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)

main.o : main.c 
filedistance.o : Lib/file_distance.h file_distance.c Lib/leven.h
leven.o : Lib/leven.h leven.c
time.o : Lib/time.h timer.c
clean:
	rm -rf $(OBJ) $(EXEC)