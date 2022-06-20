#include "Engine.h"
//Separate file for handling all the commands

void Engine::Run()
{
	char buff[BUFF_SIZE];
	while (std::cin.getline(buff, BUFF_SIZE) && isRunning) {
		onUpdate(buff);
	}
}

void Engine::onUpdate(const char* line)
{
	if (cmpStr_s("open ", strlen("open "), line) == 0) {
		setFileName(line + strlen("open "));
	}

	else if (cmpStr_s("add_planet ", strlen("add_planet "), line) == 0) {
		Planet A(line + strlen("add_planet "));
		A.saveToFile(fn1.getPtr());
	}

	else if (cmpStr_s("saveas ", strlen("saveas "), line) == 0) {
		copyFile(fn1.getPtr(), line + strlen("saveas "));
	}

	else if (cmpStr_s("create_jedi ", strlen("create_jedi "), line) == 0) {
		size_t n = 0;

		//planet name
		n = getPos(line, 2);
		String pn(line + n, wordLen(line + n));

		//jedi name
		n = getPos(line, 3);
		String jn(line + n, wordLen(line + n));

		//jedi rang
		n = getPos(line, 4);
		String r(line + n, wordLen(line + n));
		int rang = strToInt(r);

		//jedi age
		n = getPos(line, 5);
		String a(line + n, wordLen(line + n));
		int age = strToInt(a);

		//jedi sword color
		n = getPos(line, 6);
		String sc(line + n, wordLen(line + n));

		//jedi strength
		n = getPos(line, 7);
		String st(line + n, wordLen(line + n));
		double strength = strToDouble(st);

		Jedi A(jn, rang, age, sc, strength);
		addJediToFile(pn, A);
	}

	else if (cmpStr_s("removeJedi ", strlen("removeJedi "), line) == 0) {
		size_t n = 0;
		n = getPos(line, 2);
		String planetName(line + n, wordLen(line + n));
		n = getPos(line, 3);
		String jediName(line + n, wordLen(line + n));

		removeJediFromFile(planetName,jediName);
	}

	else if (cmpStr_s("promote_jedi ", strlen("promote_jedi "), line) == 0) {
		size_t n = 0;
		n = getPos(line, 2);
		String planetName(line + n, wordLen(line + n));
		n = getPos(line, 3);
		String jediName(line + n, wordLen(line + n));
		
		removeJediFromFile(planetName, jediName);
	}

}
