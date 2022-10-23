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
	std::cout << "Delete last element in list 1 - pop_back(): " << std::endl;
	l.pop_back();
	l.print();
	std::cout << "Delete first element in list 1 - pop_front(): " << std::endl;
	l.pop_front();
	l.print();
	std::cout << "Size of list 1 : " << l.size() << std::endl;
	std::cout << "Is list 1 empty? " << l.is_empty() << std::endl;
	std::cout << "Delete element in second position in list 1 - erase(2): " << std::endl;
	l.erase(2);
	l.print();
	std::cout << "Change elements with positions 0 and 2 in list 1 - swap(2, 0): " << std::endl;
	l.swap(2, 0);
	l.print();
	std::cout << "Change elements with positions 1 and 2 in list 1 - swap(1, 2): " << std::endl;
	l.swap(1, 2);
	l.print();
	std::cout << "Change elements with positions 0 and 1 in list 1 - swap(1, 0): " << std::endl;
	l.swap(1, 0);
	l.print();
	std::cout << "Give the value of element in 1 position in list 1 - operator[](1): " << l.operator[](1) << std::endl;

	



	std::cout << std::endl << "Add last element in empty list - push_back(16): " << std::endl;
	l1.push_back(16);
	l1.print();
	l1.pop_back();
	std::cout << "Delete last element pop_back() and add first element in empty list - push_front(4): " << std::endl;
	l1.push_front(4);
	l1.print();
	l1.pop_front();
	std::cout << "Delete first element pop_front() and add an element in zero position in empty list - insert(0, 1): " << std::endl;
	l1.insert(0, 1);
	l1.print();
	std::cout << "Size of this list : " << l1.size() << std::endl;
	std::cout << "Clear this list..." << std::endl;
	l1.clear();
	std::cout << "Is this list empty? " << l1.is_empty() << std::endl;


}