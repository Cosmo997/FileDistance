CC = gcc
OBJ = mainProva.o franco.o
EXEC = prova

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)

franco.o : franco.h franco.c

mainProva.o : mainProva.c

clean:
	rm -rf $(OBJ) $(EXEC)