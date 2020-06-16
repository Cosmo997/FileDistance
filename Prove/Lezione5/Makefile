CC = gcc
FLAGS = -Wno-pointer-to-int-
OBJ = mainProva.o franco.o
EXEC = prova

$(EXEC): $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

franco.o : franco.h franco.c

mainProva.o : mainProva.c

clean:
	rm -rf $(OBJ) $(EXEC)