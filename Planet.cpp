#include "Planet.h"
//#pragma warning( disable : 6386)

void Planet::copyFrom(const Planet& other) {
	name = other.name;
	Jcount = other.Jcount;
	Jcap = other.Jcap;
	//jedis = new Jedi * [other.Jcap];
	jedis = new Jedi * [Jcap];
	for (size_t i = 0; i < Jcount; i++) {
		jedis[i] = new Jedi(*other.jedis[i]); //Jedi** jedis //jedis[i] = *(**jedis + i) = *jedis[i] = pointer 
	}
}
void Planet::free() {
	for (size_t i = 0; i < Jcount; i++) {
		delete jedis[i];
	}
	delete[] jedis;
}
void Planet::resize() {
	Jcap *= 2;
	Jedi** tempJedis = new Jedi* [Jcap];
	for (size_t i = 0; i < Jcount; i++) {
		tempJedis[i] = new Jedi(*jedis[i]);
	}
	free();
	jedis = tempJedis;
}

void Planet::addJedi(const Jedi& newJedi)
{
	if (Jcount == Jcap)
		resize();
	jedis[Jcount++] = new Jedi(newJedi);
	//Jcount++;
}

void Planet::printAll()
{
	for (size_t i = 0; i < Jcount; i++) {
		std::cout << i + 1 << ") ";
		jedis[i]->print();
	}
}

Planet::Planet(const char* _name) {
	name = _name;
	Jcount = 0;
	Jcap = 2;
	jedis = new Jedi* [Jcap];
}
Planet::Planet(const Planet* other)
{
	copyFrom(other);
}
Planet& Planet::operator=(const Planet& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Planet::~Planet() {
	free();
}