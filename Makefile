CC = gcc
OBJ = main.o linked_list.o file_distance.o leven.o timer.o file_handler.o finder.o
EXEC = filedistance

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)
all : filedistance
linked_list.o : linked_list.h linked_list.c
file_distance.o : file_distance.h file_distance.c leven.h linked_list.h file_handler.h timer.h finder.h
main.o : main.c
leven.o : leven.h leven.c linked_list.h
timer.o : timer.h timer.c
file_handler.o : file_handler.h file_handler.c linked_list.h
finder.o : finder.h finder.c
clean:
	rm -rf $(OBJ) $(EXEC)
