CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = mainProva.c franco.h
OBJ = $(SRC:.cc=.o)
EXEC = mainProva.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

franco.o : franco.c franco.h

mainProva.o : mainProva.c

clean:
	rm -rf $(OBJ) $(EXEC)