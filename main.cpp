#include <iostream>
#include "Planet.h"

int main() {
	Planet A("Mars");
	for (int i = 0; i < 23; i++) A.addJedi(Jedi("Stanko", rand() % 8 + 1, 18, "purple", (rand() % 500) / 10.0));
	A.printAll();

	std::cout << "\n";
	Jedi St("Stanko", rand() % 8 + 1, 18, "purple", (rand() % 500) / 10.0);
	St.print();

	//St.saveToFile("jediCollection.txt");
	//std::ofstream file("planetCollection.txt");
	//if (file.is_open()) {
		//A.saveToFile("planetCollection.txt");
	//}
	//file.close();
	

	return 0;
}