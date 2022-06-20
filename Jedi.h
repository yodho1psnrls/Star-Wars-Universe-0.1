#pragma once
#include "String.h"
#include <iostream>
#include <fstream>
#include <math.h>
#define BUFF_SIZE 1024

class Jedi {
	String name;
	unsigned rang; //enum //ot 1 do 8
	unsigned age;
	String swordColor;
	double strength;
	void setName(const char*);
	void copyFrom(const Jedi&);

public:
	void print() const;
	void saveToFile(const char* fileName) const;
	void saveToFile(std::ofstream& file) const;
	void loadFromFile(const char* fileName);

	String getName() const;
	unsigned getRang() const;
	unsigned getAge() const;
	double getStrength() const;


	void promote(const double mul);
	void demote(const double mul);

	Jedi(const String&);
	Jedi(const char*, const unsigned, const unsigned, const char*, const double);
	Jedi(const String&, const unsigned, const unsigned, const String&, const double);
	Jedi(const Jedi&);
	Jedi& operator=(const Jedi&);
	//~Jedi() = default;

};