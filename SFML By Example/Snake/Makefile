snake: main.o Snake.o World.o Game.o Window.o
	g++ main.o Snake.o World.o Game.o Window.o -o snake -L../../../SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Snake.h World.h
	g++ -c main.cpp -I../../../SFML/include

Window.o: Window.cpp Window.h
	g++ -c Window.cpp -I../../../SFML/include

Snake.o: Snake.cpp Snake.h
	g++ -c Snake.cpp -I../../../SFML/include

World.o: World.cpp World.h
	g++ -c World.cpp -I../../../SFML/include

Game.o: Game.cpp Game.h World.h Window.h
	g++ -c Game.cpp -I../../../SFML/include

clean: 
	rm snake main.o Snake.o World.o Game.o Window.o

