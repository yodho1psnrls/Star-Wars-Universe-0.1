#pragma once
#define fileName1 "Data1.txt"
#define fileName2 "Data2.txt"
#include "Planet.h"

class Engine {
	String fn1;
	String fn2;
	bool isRunning;

	void swapFileNames();
	bool isFileEmpty(const String& fn) const;
	size_t fileLength(const String& fn) const;
	bool areFilesCorrect();

	void truncSmallerFile() const;

public:
	const char* getCurrentName() const;

	void addJediToFile(const char* planetName, const Jedi& _jedi);
	void addJediToFile(const String& planetName, const Jedi& _jedi);
	void removeJediFromFile(const char* planetName, const String& jediName);
	void removeJediFromFile(const String& planetName, const String& jediName);

	void copyFile(const char* from, const char* to);

	void Run();
	void onUpdate(const char*);
	void setFileName(const char*);

	Engine();
	Engine(const char*);
	Engine(const char*, const char*);
};