CC = gcc
OBJ = main.o file_distance.o leven.o time.o
EXEC = filedistance

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)

main.o : main.c 
filedistance.o : file_distance.h file_distance.c leven.h
leven.o : leven.h leven.c
time.o : time.h time.c
clean:
	rm -rf $(OBJ) $(EXEC)