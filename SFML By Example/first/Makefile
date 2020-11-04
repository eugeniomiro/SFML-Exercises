rectangle: main.o
	g++ main.o -o rectangle -L../../../SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -I../../../SFML/include

clean: 
	rm rectangle main.o

