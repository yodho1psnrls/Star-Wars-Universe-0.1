#include <iostream>
#include "Planet.h"

int main() {
	Planet A("Mars");
	for (int i = 0; i < 1280; i++)
		A.addJedi(Jedi("Stanko", rand() % 8 + 1, 18, "purple", (rand() % 500) / 10.0));
	A.printAll();
	return 0;
}