sfml-first: main.o
	g++ main.o -o sfml-first -L../SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -I../SFML/include

clean: 
	rm sfml-first main.o

