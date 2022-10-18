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
		Node* previous = first;
		for (int i = 0; i < position - 1; i++) {
			previous = previous->next;
		}
		Node* temp;
		temp = previous->next;
		previous->next = newNode;
		newNode->next = temp;
		newNode->prev = previous;
		temp->prev = newNode;
	}
};

void List::print() {
	Node* temp = first;
	while (temp != last) {
		std::cout << temp->value;
		temp = temp->next;
	}
}

void List::push_back(int value) {
	Node* newNode = new Node;
	newNode->value = value;

	last->next = newNode;
}
