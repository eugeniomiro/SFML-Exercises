snake: main.o Snake.o World.o
	g++ main.o Snake.o World.o -o snake -L../../../SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Snake.h World.h
	g++ -c main.cpp -I../../../SFML/include

Snake.o: Snake.cpp Snake.h
	g++ -c Snake.cpp -I../../../SFML/include

World.o: World.cpp World.h
	g++ -c World.cpp -I../../../SFML/include

clean: 
	rm snake main.o Snake.o World.o

