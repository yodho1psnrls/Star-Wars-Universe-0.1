#pragma once
#define fileName1 "Data1.txt"
#define fileName2 "Data2.txt"
#include "Planet.h"

class Engine {
	String fn1;
	String fn2;

	void swapFileNames();
	bool isFileEmpty(const String& fn) const;
	size_t fileLength(const String& fn) const;
	bool areFilesCorrect();

	void truncSmallerFile() const;

public:
	const char* getCurrentName() const;

	void addJediToFile(const char* planetName, const Jedi& _jedi);
	void removeJediFromFile(const char* planetName, const String& jediName);

	Engine();
	Engine(const char*, const char*);
	//void Run();
};