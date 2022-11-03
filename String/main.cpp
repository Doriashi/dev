#include "String.h"
#include <iostream>
#include <stdio.h>

int main()
{
	//setlocale(LC_ALL, "ru");
	String str_1("Test 1");
	std::cout << "Constructor 1:" << std::endl;
	str_1.print();
	std::cout << std::endl;

	size_t len = 3;
	String str_2(len, '2');
	std::cout << "Constructor 2:" << std::endl;
	str_2.print();
	std::cout << std::endl;

	str_1.append(str_2);
	std::cout << "Adding a line:" << std::endl;
	str_1.print();
	std::cout << std::endl;

	String str_3(str_2);
	std::cout << "Copy Constructor:" << std::endl;
	str_3.print();
	std::cout << std::endl;

	str_2 = str_1;
	std::cout << "Assignment Operator:" << std::endl;
	str_2.print();
	std::cout << std::endl;

}