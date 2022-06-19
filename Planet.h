#pragma once
#define BUFF_SIZE 1024
#include "Jedi.h"
#include <cstring> //zaradi std::getline
//#include <iostream>

//current file true ~ fileName1 and false ~ fileName2
//bool S = true;

class Planet {
	String name;
	Jedi** jedis;
	size_t Jcount;
	size_t Jcap; //jedi capacity
	size_t Y; //line number / position of the Planet in the txt file

	void copyFrom(const Planet&);
	void free();
	void resize();

public:
	void addJedi(const Jedi&);
	void addJedi(const char* name, const unsigned rang, const unsigned age, const char* swordColor, const double strength);
	void addJedi(const String& name, const unsigned rang, const unsigned age, const String& swordColor, const double strength);
	//void removeJediFromFile(const Jedi&) const;
	void printAll();
	void saveToFile(const char*) const;
	void loadFromFile(const char* fileName);

	size_t getPopulation() const;
	String getName() const;
	size_t getLineNumber() const;
	//Planet();
	Planet(const char*);
	Planet(const Planet&);
	Planet& operator=(const Planet&);
	~Planet();
};
