CC = gcc
OBJ = main.o istruction_structure.o istruction_data.o
EXEC = prova

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)

main.o : main.c 
istruction_data.o : istruction_data.c istruction_data.h
istruction_structure.o : istruction_structure.c istruction_structure.h
clean:
	rm -rf $(OBJ) $(EXEC)