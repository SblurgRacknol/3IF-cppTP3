C_FLAGS=-c -Wall -DMAP -pedantic -ansi -std=c++11

main : main.o Trajet.o TrajetSimple.o TrajetCompose.o tabTrajets.o Catalogue.o main.h
	g++ -o main main.o Trajet.o TrajetSimple.o TrajetCompose.o tabTrajets.o Catalogue.o

Trajet.o : Trajet.cpp Trajet.h
	g++ $(C_FLAGS) Trajet.cpp

TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h Trajet.h
	g++ $(C_FLAGS) TrajetSimple.cpp

TrajetCompose.o : TrajetCompose.cpp TrajetCompose.h Trajet.h tabTrajets.h TrajetSimple.h
	g++ $(C_FLAGS) TrajetCompose.cpp

tabTrajets.o : tabTrajets.cpp tabTrajets.h TrajetCompose.h Trajet.h TrajetSimple.h
	g++ $(C_FLAGS) tabTrajets.cpp

Catalogue.o : Catalogue.cpp Catalogue.h Trajet.h tabTrajets.h
	g++ $(C_FLAGS) Catalogue.cpp

main.o : main.cpp main.h Trajet.h TrajetSimple.h TrajetCompose.h tabTrajets.h
	g++ $(C_FLAGS) main.cpp
	
