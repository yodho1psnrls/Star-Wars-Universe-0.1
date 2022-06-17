#include "String.h"
#include<iostream>
#include<cstring>
int myPow(int n, const int e) {
	if (e == 0) return 1;
	else if (n == 0) return 0;
	else {
		int t = 1;
		for (int i = 0; i < e; i++) {
			t *= n;
		}
		return t;
	}
	return 0;
}

int numLen(int n) {
	int size = 1;
	while (n >= 10) {
		n /= 10;
		size++;
	}
	return size;
}

void String::createEmpty() {
	str = new char[1];
	str[0] = '/0';
	size = 0;
}
void String::copyStr(const String& other) {
	size = strlen(other.str);
	str = new char[size + 1];
	strcpy_s(str, size + 1, other.str);
}
void String::copyCharArr(const char* other) {
	// nullptr ~~ false
	if (other != nullptr) { 
		size = strlen(other);
		str = new char[size + 1];
		strcpy_s(str, size + 1, other);
	}
	else {
		createEmpty();
	}
}
void  String::clear() {
	delete[] str;
}


//=======================public====================//
String::String() {
	createEmpty();
}
String::String(const char* other) {
	copyCharArr(other);
}
String::String(const char other) {
	str = new char[2];
	str[0] = other;
	str[1] = '/0';
	size = 1;
}

String::String(const String& other) {
	copyStr(other);
}
String::~String() {
	clear();
}
String& String::operator=(const String& other) {
	if (this != &other) {
		clear();
		copyStr(other);
	}
	return *this;
}
String& String::operator=(const char* other) {
	if (strcmp(str, other) != 0) {
		clear();
		copyCharArr(other);
	}
	return *this;
}

const char* String::getStr() const {
	return str;
}
const size_t  String::getLen() const {
	return size;
}

bool operator==(const String& lhs, const String& rhs) {
	return strcmp(lhs.getStr(), rhs.getStr()) == 0;
}

//The functions below this line are from here:
//https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Sem.%2009/StringPool/MyString/MyString.h
std::ostream& operator<<(std::ostream& stream, const String& str) {
	//stream << str.getStr();
	stream << str.str;
	return stream;
}

std::istream& operator>>(std::istream& stream, String& str) {
	str.clear();
	char buff[1024];
	stream >> buff;

	str.size = strlen(buff);
	str.str = new char[str.size + 1];
	strcpy_s(str.str, str.size + 1, buff);

	return stream;
}
/*
void String::copyNumber(const int n) {
	createEmpty();
	int u = 0;
	for (int i = 0; i < numLen(n); i++) {
		u = int(n / myPow(10, i) % 10);
		concat(String(char(u + 30)));
		size++;
	}
}
String::String(const int digit) {
	copyNumber(digit);
}
void String::concat(const String& other)
{
	char* temp = new char[getLen() + other.getLen() + 1];
	strcpy_s(temp, size + 1, str);
	size = size + other.getLen();
	strcat_s(temp,size + 1, other.str);

	delete[] str;
	str = temp;
	
}
String& String::operator+=(const String& other) {
	concat(other);
	return *this;
}
String operator+(const String & lhs, const String & rhs) {
	String copyOfLeft(lhs);
	copyOfLeft += rhs;
	return copyOfLeft;
}
String& String::operator+=(const char* other) {
	concat(String(other));
	return *this;
}
*/