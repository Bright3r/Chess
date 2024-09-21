SRC = ./src/main.cpp ./src/window.cpp
CFLAGS = -Wall -Wextra -pedantic -g -I./src/include
LDFLAGS = -L./src
LIBS = -lSDL2 -lSDL2_ttf -lSDL2_mixer -lm -pthread
DEST = main

all:
	g++ $(CFLAGS) $(SRC) $(LDFLAGS) $(LIBS) -o $(DEST)

clean:
	rm -f $(DEST)
