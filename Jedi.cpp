#include "Jedi.h"

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

Jedi::Jedi(const char* _name, const unsigned _rang, const unsigned _age, const char* _sc, const double _strength) {
	name = _name;
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
