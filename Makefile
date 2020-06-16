CC = gcc
OBJ = main.o file_distance.o leven.o timer.o istruction_structure.o file_modifier.o
EXEC = filedistance

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)
all : filedistance
main.o : main.c
istruction_structure.o : Lib/istruction_structure.h istruction_structure.c
filedistance.o : Lib/file_distance.h file_distance.c Lib/leven.h
leven.o : Lib/leven.h leven.c Lib/istruction_structure.h istruction_structure.c
time.o : Lib/time.h timer.c
file_modifier.o : Lib/file_modifier.h file_modifier.c Lib/istruction_structure.h
clean:
	rm -rf $(OBJ) $(EXEC)