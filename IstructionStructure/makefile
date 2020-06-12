CC = gcc
OBJ = main.o istruction_structure.o
EXEC = prova

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)

main.o : main.c 
istruction_structure.o : istruction_structure.c istruction_structure.h
clean:
	rm -rf $(OBJ) $(EXEC)