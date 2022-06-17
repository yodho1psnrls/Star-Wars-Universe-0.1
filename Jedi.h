#pragma once
#include "String.h"
#include <iostream>

class Jedi {
	String name;
	unsigned rang; //enum //ot 1 do 8
	unsigned age;
	String swordColor;
	double strength;
	void copyFrom(const Jedi&);

public:
	void print() const;

	//Jedi();
	Jedi(const char*, const unsigned, const unsigned, const char*, const double);
	Jedi(const Jedi&);
	Jedi& operator=(const Jedi&);
	//~Jedi() = default;

};