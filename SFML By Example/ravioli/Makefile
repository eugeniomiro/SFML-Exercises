ravioli: main.o Game.o Window.o
	g++ main.o Game.o Window.o -o ravioli -L../../../SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Game.hpp
	g++ -c main.cpp -I../../../SFML/include

Game.o: Game.cpp Game.hpp Window.hpp
	g++ -c Game.cpp -I../../../SFML/include

Window.o: Window.cpp Window.hpp
	g++ -c Window.cpp -I../../../SFML/include

clean: 
	rm ravioli main.o Game.o Window.o

