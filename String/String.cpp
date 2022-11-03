#include "String.h"

String::String(const char* str) {
	std::cout << "Constructor:" << this << std::endl;
	size = strlen(str);
	this->str = new char[size + 1];
	strcpy(this->str, str);
}

String::String(size_t n, char c) {
	std::cout << "Constructor:" << this << std::endl;
	str = new char[n + 1];
	for (int i = 0; i < n; i++) str[i] = c;
	str[n] = '\0';
	size = n;
}

String::~String() {
	std::cout << "Destructor:" << this << std::endl;
	delete[] str;
}

String::String(const String& other) {
	std::cout << "Constructor:" << this << std::endl;
	this->size = other.size;
	this->str = new char[other.size + 1];
	for (int i = 0; i < other.size; i++) this->str[i] = other.str[i];
	str[other.size] = '\0';
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] this->str;
		this->size = other.size;
		this->str = new char[other.size + 1];
		for (int i = 0; i < other.size; i++) this->str[i] = other.str[i];
		str[other.size] = '\0';
	}
	return *this;
}

void String::append(String& other) {
	size_t new_size = size + other.size;
	char* new_str = new char[new_size + 1];
	strcpy(new_str, str);
	strcpy(new_str + size, other.str);
	new_str[new_size] = '\0';
	delete[] str;
	str = new_str;
	size = new_size;
}

void String::print() {
	for (int i = 0; i < size; i++) std::cout << str[i];
}