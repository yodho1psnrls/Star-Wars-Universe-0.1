#include "Engine.h"

void Engine::swapFileNames() {
	String temp(fn1);
	fn1 = fn2;
	fn2 = temp;
}

size_t Engine::fileLength(const String& fn) const {
	char buff[1024];
	size_t y = 0;
	std::ifstream file(fn.getPtr());
	if (file.is_open()) {
		while (file.getline(buff, 1024)) {
			y++;
		}
	}
	file.close();

	return y;
}

bool Engine::isFileEmpty(const String& fn) const {

	return bool(fileLength(fn) == 0);
}

bool Engine::areFilesCorrect() {
	bool is1 = isFileEmpty(fn1);
	bool is2 = isFileEmpty(fn2);

	return ((is1 && !is2) || (!is1 && is2) || (is1 && is2));
	//return ((is1 && !is2) || (!is1 && is2));
	//return !(!is1 && !is2);
	//return !is1 || !is2;
}

void truncFile(const String& name) {
	std::ofstream file(name.getPtr() , std::ios::trunc);
	file.close();
}

void Engine::truncSmallerFile() const
{
	if (fileLength(fn1) > fileLength(fn1))
		truncFile(fn2);
	else truncFile(fn1);
}

void Engine::setFileName(const char* _fn)
{
	String f1(_fn);
	String f2(_fn);
	f1 += String("1");
	f2 += String("2");
	fn1 = f1.getPtr();
	fn2 = f2.getPtr();

	if (!areFilesCorrect()) {
		truncSmallerFile();
	}

	if (isFileEmpty(fn1) && !isFileEmpty(fn2)) swapFileNames();
}

Engine::Engine()
{
	isRunning = true;
	fn1 = fileName1;
	fn2 = fileName2;

	if (!areFilesCorrect()) {
		truncSmallerFile();
	}

	if (isFileEmpty(fn1) && !isFileEmpty(fn2)) swapFileNames();
}

Engine::Engine(const char* _fn)
{
	isRunning = true;

	String f1(_fn);
	String f2(_fn);
	f1 += String("1");
	f2 += String("2");
	fn1 = f1.getPtr();
	fn2 = f2.getPtr();

	if (!areFilesCorrect()) {
		truncSmallerFile();
	}

	if (isFileEmpty(fn1) && !isFileEmpty(fn2)) swapFileNames();
}

Engine::Engine(const char* _fn1, const char* _fn2)
{
	isRunning = true;

	fn1 = _fn1;
	fn2 = _fn2;

	if (!areFilesCorrect()) {
		truncSmallerFile();
	}

	if (isFileEmpty(fn1) && !isFileEmpty(fn2)) swapFileNames();
}

const char* Engine::getCurrentName() const
{
	return fn1.getPtr();
}

void Engine::addJediToFile(const char* planetName, const Jedi& _jedi)
{
	char buff[BUFF_SIZE];
	std::ifstream ifile(fn1.getPtr());
	std::ofstream ofile(fn2.getPtr());
	bool isAdded = false;
	if (ifile.is_open() && ofile.is_open()) {
		while (ifile.getline(buff, BUFF_SIZE)) {
			ofile << buff << "\n";
			if (buff[0] == '@' && (String(buff + 1) == planetName)) {
				_jedi.saveToFile(ofile);
				isAdded = true;

				//std::cout << "Jedi is added ! \n";
				std::cout << _jedi.getName() << " succesfuly landed on " << planetName << ". \n";
			}
		}
		if (ifile.eof() && !isAdded) {
			std::cout << "Cannot add "<<_jedi.getName()<<", There is no planet "<<planetName<<". \n";
		}
		truncFile(fn1);
		swapFileNames();
	}
	ifile.close();
	ofile.close();
}
void Engine::addJediToFile(const String& planetName, const Jedi& _jedi) {
	addJediToFile(planetName.getPtr(), _jedi);
}

void Engine::removeJediFromFile(const String& planetName, const String& jediName) {
	removeJediFromFile(planetName.getPtr(), jediName);
}

void Engine::removeJediFromFile(const char* planetName, const String& jediName)
{
	bool isInPlanet = false;
	bool isRemoved = false;
	char buff[BUFF_SIZE];
	//size_t l = jediName.getLen();
	std::ifstream ifile(fn1.getPtr());
	std::ofstream ofile(fn2.getPtr());
	if (ifile.is_open() && ofile.is_open()) {
		while (ifile.getline(buff, BUFF_SIZE)) {

			if (buff[0] == '@') {
				if (String(buff + 1) == planetName) {
					isInPlanet = true;
				}
				else isInPlanet = false;
			}
			//deletes all jedis with  this name
			//if (!(isInPlanet && (cmpStr_s(jediName.getPtr(), jediName.getLen(), buff) == 0))) { 

			//deletes only one jedi with this name
			if (!(isInPlanet && !isRemoved && (cmpStr_s(jediName.getPtr(), jediName.getLen(), buff) == 0))) {
				ofile << buff << "\n";
			}
			else {
				std::cout << jediName << " from " << planetName << " is removed. \n";
				isRemoved = true;
			}
		}
		truncFile(fn1);
		swapFileNames();
	}
	ifile.close();
	ofile.close();

	if (!isRemoved) {
		std::cout << "There is no " << jediName << " on " << planetName << " to be removed. \n";
	}
}

void Engine::copyFile(const char* from, const char* to) {
	char buff[BUFF_SIZE];
	std::ifstream ifile(from);
	std::ofstream ofile(to);
	if (ifile.is_open() && ifile.is_open()) {
		while (ifile.getline(buff, BUFF_SIZE)) {
			ofile << buff << "\n";
		}
		std::cout << "Data successfully saved. \n";
	}
	ifile.close();
	ofile.close();
}