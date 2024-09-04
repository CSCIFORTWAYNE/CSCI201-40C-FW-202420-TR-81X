all: main.cpp drink drinkOrder
	g++ -pedantic-errors -g  -fdiagnostics-color=always main.cpp drink drinkOrder -o main
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always drink.cpp -o drink 
drinkOrder: drinkOrder.h drinkOrder.cpp 
	g++ -pedantic-errors -g -c -fdiagnostics-color=always drinkOrder.cpp -o drinkOrder
