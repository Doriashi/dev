#include <iostream>
#include "List.h"


int main()
{
	Node* node_1 = new Node;
	Node* node_2 = new Node;
	node_1->value = 5;
	node_2->value = 15;

	node_1->next = node_2;
	node_2->prev = node_1;
	node_2->next = nullptr;


	List l, l1, l2, l3;
	l.first = node_1;
	l.last = node_2;
	std::cout << "list 1 : " << std::endl;
	l.print();
	std::cout << "Add last element in list 1 - push_back(16): " << std::endl;
	l.push_back(16);
	l.print();
	std::cout << "Add first element in list 1 - push_front(4): " << std::endl;
	l.push_front(4);
	l.print();
	std::cout << "Add an element in second position in list 1 - insert(2, 8): " << std::endl;
	l.insert(2, 8);
	l.print();
	std::cout << "Add an element in zero position in list 1 - insert(0, 0): " << std::endl;
	l.insert(0, 0);
	l.print();

	std::cout << "Add last element in empty list - push_back(16): " << std::endl;
	l1.push_back(16);
	l1.print();
	std::cout << "Add first element in empty list - push_front(4): " << std::endl;
	l2.push_front(4);
	l2.print();
	std::cout << "Add an element in zero position in empty list - insert(0, 1): " << std::endl;
	l3.insert(0, 1);
	l3.print();
}