#include "List.h"
#include <iostream>

void List::insert(int position, int value) {
	Node* newNode = new Node;
	newNode->value = value;
	
	if (first == nullptr) {
		first = newNode;
		last = newNode;
	}
	else {
		Node* temp = first;
		for (int i = 0; i < position; i++) {
			temp = temp->next;
		}
		
		Node* pred = temp->prev;
		
		newNode->next = temp;
		newNode->prev = pred;
		temp->prev = newNode;
		if (pred != nullptr)
			pred->next = newNode;
		else
			first = newNode;
		
	}
};

void List::print() {
	Node* temp = first;
	while (!(temp == nullptr)) {
		std::cout << temp->value << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}

void List::push_back(int value) {
	Node* newNode = new Node;
	newNode->value = value;

	if (first == nullptr) {
		first = newNode;
		last = newNode;
	}
	else {
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}
}

void List::push_front(int value) {
	Node* newNode = new Node;
	newNode->value = value;

	if (first == nullptr) {
		first = newNode;
		last = newNode;
	}
	else {
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
}
