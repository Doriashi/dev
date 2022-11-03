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

void List::pop_back() {
	if (last == nullptr)
		return;
	if (last->prev == nullptr) {
		delete last;
		first = nullptr;
		last = nullptr;
		return;
	}

	Node* temp = last->prev;
	delete last;
	last = temp;
	last->next = nullptr;
}

void List::pop_front() {
	if (first == nullptr)
		return;

	if (first->next == nullptr) {
		delete first;
		first = nullptr;
		last = nullptr;
		return;
	}

	Node* temp = first->next;
	delete first;
	first = temp;
	first->prev = nullptr;
}

int List::size() {
	int size = 0;
	Node* temp = first;
	while (temp != nullptr) {
		temp = temp->next;
		size++;
	}
	return size;
}

bool List::is_empty() {
	if (List::size() == 0) return true;
	else return false;
}

void List::clear() {
	while (first != nullptr) {
		Node* temp = first->next;
		delete first;
		first = temp;
	}
}

void List::erase(int position) {
	Node* temp = first;
	for (int i = 0; i < position; i++) {
		temp = temp->next;
	}

	Node* pred = temp->prev;
	Node* foll = temp->next;
	if (pred != nullptr)
		pred->next = foll;
	if (foll != nullptr)
		foll->prev = pred;
	delete temp;
}

void List::swap(int position1, int position2) {
	Node* temp1 = first;
	int pos_min = std::min(position1, position2);
	int pos_max = std::max(position1, position2);
	for (int i = 0; i < pos_min; i++) {
		temp1 = temp1->next;
	}

	Node* temp2 = first;
	for (int i = 0; i < pos_max; i++) {
		temp2 = temp2->next;
	}
	
	Node* pred1 = temp1->prev;
	Node* pred2 = temp2->prev;
	Node* foll1 = temp1->next;
	Node* foll2 = temp2->next;
	if (temp2 == foll1)
	{
		temp2->next = temp1;
		temp2->prev = pred1;
		temp1->next = foll2;
		temp1->prev = temp2;
		if (foll2 != nullptr)
			foll2->prev = temp1;
		else last = temp1;
		if (temp1 != first)
			pred1->next = temp2;
		else first = temp2;
	}
	else
	{
		if (temp1 != first)
			pred1->next = temp2;
		else first = temp2;
		temp2->next = foll1;
		pred2->next = temp1;

		temp1->next = foll2;
		temp2->prev = pred1;
		if (foll2 != nullptr)
			foll2->prev = temp1;
		else last = temp1;
		temp1->prev = pred2;
		foll1->prev = temp2;
	}
}

int List::operator[] (const int index) {
	Node* temp = first;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp->value;
}