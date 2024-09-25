all: main.cpp clock clockExcept
	g++ -pedantic-errors -g  -fdiagnostics-color=always main.cpp clock clockExcept -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always clock.cpp -o clock
clockExcept: clockExcept.h clockExcept.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always clockExcept.cpp -o clockExcept
