#include "Planet.h"
#include <iostream>
#include <string>
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
}

void Planet::addJedi(const char* name, const unsigned rang, const unsigned age, const char* swordColor, const double strength)
{
	if (Jcount == Jcap)
		resize();
	jedis[Jcount++] = new Jedi(name, rang, age, swordColor, strength);
	//Jcount++;
}

void Planet::addJedi(const String& name, const unsigned rang, const unsigned age, const String& swordColor, const double strength)
{
	if (Jcount == Jcap)
		resize();
	jedis[Jcount++] = new Jedi(name.getPtr(), rang, age, swordColor.getPtr(), strength);
	//Jcount++;
}


void Planet::printAll()
{
	for (size_t i = 0; i < Jcount; i++) {
		std::cout << i + 1 << ") ";
		jedis[i]->print();
	}
}

void Planet::saveToFile(const char* fileName) const {
	std::ofstream file(fileName , std::ios::app);
	if (file.is_open()) {
		file << "@" << name <<"\n";
		file.close();
		for (size_t i = 0; i < Jcount; i++) {
			jedis[i]->saveToFile(fileName);
		}
	}

	file.close();
}

void Planet::loadFromFile(const char* fileName)
{
	char buff[BUFF_SIZE];

	String tempName;
	unsigned tempRang; //enum //ot 1 do 8
	unsigned tempAge;
	String tempSwordColor;
	double tempStrength;

	bool isPlanetFound = false;

	std::ifstream file(fileName);
	if (file.is_open()) {
		while (file.getline(buff, BUFF_SIZE)) {
			Y++;
			if (buff[0] == '@' && (String(buff + 1) == name)) {
				while (file >> tempName >> tempRang >> tempAge >> tempSwordColor >> tempStrength && tempName[0] != '@') {
					addJedi(tempName, tempRang, tempAge, tempSwordColor, tempStrength);
				}
				isPlanetFound = true;
				break;
			}
		}
		if (isPlanetFound)
			std::cout << "Planet succesfuly loaded ! \n";
		else std::cout << "Plannet NOT loaded. There is no planet with that name in the .txt file \n";
	}
	else std::cout << "Cannot open file ! \n";
	file.close();
}

size_t Planet::getPopulation() const
{
	return Jcount;
}

String Planet::getName() const
{
	return name;
}

size_t Planet::getLineNumber() const
{
	return Y;
}

Planet::Planet(const char* _name) {
	name = _name;
	Jcount = 0;
	Jcap = 2;
	jedis = new Jedi* [Jcap];
	Y = 0; //1
}
Planet::Planet(const Planet& other)
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