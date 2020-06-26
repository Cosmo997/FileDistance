CC = gcc
OBJ = main.o istruction_structure.o file_distance.o leven.o timer.o file_handler.o finder.o
EXEC = filedistance

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)
all : filedistance
istruction_structure.o : Lib/istruction_structure.h istruction_structure.c
file_distance.o : Lib/file_distance.h file_distance.c Lib/leven.h Lib/istruction_structure.h Lib/file_handler.h Lib/timer.h Lib/finder.h
main.o : main.c
leven.o : Lib/leven.h leven.c Lib/istruction_structure.h
timer.o : Lib/timer.h timer.c
file_handler.o : Lib/file_handler.h file_handler.c Lib/istruction_structure.h
finder.o : Lib/finder.h finder.c
clean:
	rm -rf $(OBJ) $(EXEC)
