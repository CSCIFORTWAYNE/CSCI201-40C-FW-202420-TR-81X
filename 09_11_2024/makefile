all: product clock order main.cpp
	g++ -pedantic-errors -g  -fdiagnostics-color=always main.cpp product clock order -o main
product: product.h product.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always product.cpp -o product
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always clock.cpp -o clock
order: order.h order.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always order.cpp -o order
