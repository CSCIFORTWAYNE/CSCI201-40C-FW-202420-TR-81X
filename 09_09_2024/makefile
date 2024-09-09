all: person employee
	g++ -pedantic-errors -g main.cpp person employee -o main
person: person.h person.cpp
	g++ -pedantic-errors -g person.cpp -c -o person
employee: person employee.h employee.cpp
	g++ -pedantic-errors -g employee.cpp -c -o employee