#include "String.h"

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

const char* String::getPtr() const {
	return str;
}
const size_t  String::getLen() const {
	return size;
}

const char String::operator[](const size_t i) const
{
	return str[i];
}

bool operator==(const String& lhs, const String& rhs) {
	return strcmp(lhs.getPtr(), rhs.getPtr()) == 0;
}

bool operator!=(const String& lhs, const String& rhs) {
	return strcmp(lhs.getPtr(), rhs.getPtr()) != 0;
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

void String::concat(const String& other)
{
	char* temp = new char[size + other.size + 1];
	for (size_t i = 0; i < size; i++) {
		temp[i] = str[i];
	}
	for (size_t i = 0; i < other.size + 1; i++) {
		temp[size + i] = other.str[i];
	}
	size = size + other.size;
	delete[] str;
	str = temp;
	
}

String& String::operator+=(const String& other) {
	concat(other);
	return *this;
}
String& String::operator+=(const char* other) {
	concat(String(other));
	return *this;
}
String operator+(const String & lhs, const String & rhs) {
	String copyOfLeft(lhs);
	copyOfLeft += rhs;
	return copyOfLeft;
}

int cmpStr_s(const char* cr1, const size_t l, const char* cr2)
{
	int a = 0;
	for (size_t i = 0; i < l; i++) {
		a += int(cr1[i]) - int(cr2[i]);
	}
	return a;
}
