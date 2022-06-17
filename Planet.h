#pragma once
#include "Jedi.h"
//#include <iostream>

class Planet {
	String name;
	Jedi** jedis;
	size_t Jcount;
	size_t Jcap; //jedi capacity

	//void copyJedis(const Jedi**);
	void copyFrom(const Planet&);
	void free();
	void resize();

public:
	void addJedi(const Jedi&);
	void printAll();
	Jedi getStrongestJedi() const;

	//Planet();
	Planet(const char*);
	Planet(const Planet*);
	Planet& operator=(const Planet&);
	~Planet();
};
