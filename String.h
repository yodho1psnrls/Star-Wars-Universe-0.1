#pragma once
#include <fstream>
class String {
	char* str;
	size_t size;

	void copyStr(const String&);
	void copyCharArr(const char*);
	void createEmpty();
	void clear();
	//void copyNumber(const int);

public:
	String();
	String(const char*);
	String(const char);
	String(const String&);
	//String(const int); //NAPRAVI GO
	~String();
	String& operator=(const String&);
	String& operator=(const char*);
	
	const char* getStr() const;
	const size_t getLen() const;

	friend std::ostream& operator<<(std::ostream&,const String&);
	friend std::istream& operator>>(std::istream&, String&);
	//void concat(const String&);
	//String& operator+=(const String& other);
	//String& operator+=(const char*);
};
//String operator+(const String& lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
//char* findWord()
//bool operator<(const char* lhs, const char* rhs);