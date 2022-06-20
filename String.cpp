#include "String.h"

void String::createEmpty() {
	str = new char[1];
	str[0] = '\0';
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

String::String(const char a)
{
	str = new char[2];
	str[0] = a;
	str[1] = '\0';
	size = 1;
}

String::String(const char* other, const size_t l) //l ~~ length
{
	str = new char[l + 1];
	for (size_t i = 0; i < l; i++) {
		str[i] = other[i];
	}
	str[l] = '\0';
	size = l;
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
/*
void String::concat(const char cr)
{
	char* temp = new char[size + 2];
	for (size_t i = 0; i < size; i++) {
		temp[i] = str[i];
	}
	temp[size] = cr;
	temp[size + 1] = '\0';
	delete[] str;
	str = temp;
	size++;
}*/

String& String::operator+=(const String& other) {
	concat(other);
	return *this;
}
String& String::operator+=(const char* other) {
	concat(String(other));
	return *this;
}
/*
String& String::operator+=(const char s) {
	concat(s);
	return *this;
}*/
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

double myPow(const double a, const int b) {
	double x = 1.0;
	if (b > 0) {
		for (int i = 0; i < b; i++) {
			x *= a;
		}
	}
	else if (b < 0) {
		for (int i = 0; i < (-1 * b); i++) {
			x /= a;
		}
	}
	return x;
}

int strToInt(String& str) {
	return strToInt(str.getPtr());
}

int strToInt(const char* str) {
	int x = 0;
	int n = int(wordLen(str));
	for (int i = 0; i < n; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			x += int(int(str[i]) - int('0')) * int(myPow(10, n - i - 1));
		}
	}
	return x;
}

/*
size_t strToSize_t(const char* str) {
	size_t x = 0;
	size_t y = 1;
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		if (str[i] == ' ') {
			y = myPow(10, n - i);
			break;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			x += int(int(str[i]) - int('0')) * int(myPow(10, n - i - 1));
		}
	}
	return x / y;
} */

bool isStrDecimal(const char* str) {
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		if (str[i] == '.') return true;
	}
	return false;
}

double strToDouble(String& str) {
	return strToDouble(str.getPtr());
}

size_t getCharPos(const char* str, const char a) {
	size_t i = 0;
	while (str[i]!='\0' && str[i] != a) {
		i++;
	}
	return i;
}

double strToDouble(const char* str)
{
	double d = 0.0;
	int l = 0;
	//136.72 ~~ 1*100 + 3*10 + 6*1 + 7*0.1 + 2*0.01
	int n = wordLen(str); //5
	if (isStrDecimal(str)) {
		l = getCharPos(str, '.');
		for (int i = 0; i < n; i++) {
			if (str[i] == ' ') {
				break;
			}
			if (str[i] >= '0' && str[i] <= '9') {
				//n - n + getpos + 1 - 1 - i = getpos - i 
				d += double(int(str[i]) - int('0')) * myPow(10, l - i - 1);
				//d += double(double(str[i]) - double('0')) * myPow(10, l - i - 1));
			}
			//This should happen only once
			else if (str[i] == '.') {
				//i++;
				l++;
			}
		}
	}
	else {
		d = double(strToInt(str));
	}
	
	return d;
}

size_t wordLen(const char* str) {
	size_t i = 0;
	while (str[i] != '\0' && str[i] != ' ') {
		i++;
	}
	return i;
}

size_t getPos(const char* str, const size_t a) {
	size_t i = 0;
	size_t c = 1;
	if (a == 0) c = 0;
	while (str[i] != '\0') {
		if (str[i] == ' ') c++;
		if (c == a) break;
		i++;
	}
	return i + 1;
}