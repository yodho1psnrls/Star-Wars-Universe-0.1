#pragma once
#include <fstream>
#include <iostream>
#include <cstring>

class String {
	char* str;
	size_t size;

	void copyStr(const String&);
	void copyCharArr(const char*);
	void createEmpty();
	void clear();

public:
	String();
	String(const char*);

	//String(const char);
	String(const String&);
	~String();
	String& operator=(const String&);
	String& operator=(const char*);
	
	const char* getPtr() const;
	const size_t getLen() const;

	const char operator[](const size_t) const;
	friend std::ostream& operator<<(std::ostream&,const String&);
	friend std::istream& operator>>(std::istream&, String&);
	void concat(const String&);
	String& operator+=(const String& other);
	String& operator+=(const char*);
};
String operator+(const String& lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
int cmpStr_s(const char* cr1, const size_t l, const char* cr2);