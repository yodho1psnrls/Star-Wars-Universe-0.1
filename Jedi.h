#pragma once
#include "String.h"
#include <iostream>
#include <fstream>

class Jedi {
	String name;
	unsigned rang; //enum //ot 1 do 8
	unsigned age;
	String swordColor;
	double strength;
	void copyFrom(const Jedi&);

public:
	void print() const;
	void saveToFile(const char* fileName) const;
	//void saveToFile(const std::ofstream& file) const;
	//void loadFromFile(const char* fileName);

	//Jedi();
	Jedi(const char*, const unsigned, const unsigned, const char*, const double);
	Jedi(const Jedi&);
	Jedi& operator=(const Jedi&);
	//~Jedi() = default;

};