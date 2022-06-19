#include "Jedi.h"

void Jedi::setName(const char* _name)
{
	size_t i = 0;
	while (_name[i] == '@' && _name[i] != '/0') {
		i++;
	}
	name = _name + i;
}

void Jedi::copyFrom(const Jedi& other)
{
	name = other.name;
	rang = other.rang;
	age = other.age;
	swordColor = other.swordColor;
	strength = other.strength;
}

void Jedi::print() const
{
	std::cout << name << ", Rank: " << rang << ", Age: " << age << ", Sword: " << swordColor << ", Strength: " << strength<<"\n";
}

void Jedi::saveToFile(const char* fileName) const
{
	std::ofstream file(fileName);
	if (file.is_open()) {
		file << name << " " << rang << " " << age << " " << swordColor << " " << strength << "\n";
	}

	file.close();
}

void Jedi::saveToFile(std::ofstream& file) const
{
		file << name << " " << rang << " " << age << " " << swordColor << " " << strength << "\n";
}

Jedi::Jedi(const char* _name, const unsigned _rang, const unsigned _age, const char* _sc, const double _strength) {
	//name = _name;
	setName(_name);
	rang = _rang;
	age = _age;
	swordColor = _sc;
	strength = _strength;
}
Jedi::Jedi(const Jedi& other) {
	copyFrom(other);
}

Jedi& Jedi::operator=(const Jedi& other)
{
	copyFrom(other);
	return *this;
}
