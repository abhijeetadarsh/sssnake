CXXFLAGS = -lcurses
CC = g++

Main: *.cpp
	$(CC) $(CXXFLAGS) Main.cpp -o Main

run: Main
	./Main

clean:
	rm Main

.PHONY: clean