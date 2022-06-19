#include <iostream>
#include "Engine.h"

int main() {
	Engine E;
		E.addJediToFile("Mars", Jedi("Stanko", rand() % 8 + 1, 18, "purple", (rand() % 500) / 10.0));
	
	E.removeJediFromFile("Mars", "halulullu");
	Planet M("Mars");
	M.loadFromFile(E.getCurrentName());
	M.printAll();

	std::cout << cmpStr_s("Jagajgjajgjagja", strlen("Jagajgjajgjagja"), "Jagajgjajgjagja 4 18 purple 4.1");

	return 0;
}