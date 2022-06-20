#include "Jedi.h"

void Jedi::setName(const char* _name)
{
	size_t i = 0;
	while (_name[i] == '@' && _name[i] != '/0') {
		i++;
	}
	//String operator=(const char*)
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
/*
void Jedi::loadFromFile(const char* fileName)
{
	char buff[BUFF_SIZE];
	size_t n = 0;
	std::ifstream file(fileName);
	if (file.is_open()) {
		while (file.getline(buff, BUFF_SIZE)) {
			String _name(buff, wordLen(buff));
			if (name == _name) {

				n = getPos(buff, 2);
				String r(buff + n, wordLen(buff + n));
				

				break;
			}
		}
	}
	file.close();
}
*/

String Jedi::getName() const
{
	return name;
}

unsigned Jedi::getRang() const
{
	return rang;
}

unsigned Jedi::getAge() const
{
	return age;
}

double Jedi::getStrength() const
{
	return strength;
}

void Jedi::promote(const double mul)
{
	if (rang < 8) rang++;
	strength *= (1.0 + mul);
}

void Jedi::demote(const double mul)
{
	if (rang > 1) rang--;
	strength *= (1.0 - mul);
}

Jedi::Jedi(const String& _name)
{
	setName(_name.getPtr());
	rang = 1;
	age = 18;
	swordColor = "white";
	strength = 15.0;
}

Jedi::Jedi(const char* _name, const unsigned _rang, const unsigned _age, const char* _sc, const double _strength) {
	setName(_name);
	rang = _rang;
	age = _age;
	swordColor = _sc;
	strength = _strength;
}
Jedi::Jedi(const String& _name, const unsigned _rang, const unsigned _age, const String& _sc, const double _strength)
{
	setName(_name.getPtr());
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
