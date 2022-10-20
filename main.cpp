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

/*
#include <iostream>
#include <forward_list>

struct Node {
	int value = 0;
	Node* next = nullptr;
};

struct List {
	Node* first = nullptr;
	int size_ = 0;

	void push_front(const int value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = first;
		first = newNode;
		size_++;
	}

	void print() {
		Node* curNode = first;
		while (!(curNode == nullptr))
		{
			std::cout << curNode->value << "\n";
			curNode = curNode->next;
		}
	};

	void clear() {
		while (first != nullptr) {
			Node* tmpNode = first->next;
			delete first;
			first = tmpNode;
		}
		size_ = 0;
	}

	void pop_front() {
		if (first != nullptr) {
			Node* tmpNode = first->next;
			delete first;
			first = tmpNode;
			size_--;
		}
	}

	bool is_empty() {
		if (first != nullptr) {
			return true;
		}
		return false;
	}

	void insert_after(int position, int value) {
		Node* curNode = first;
		int pos = 0;
		while (!(curNode == nullptr))
		{
			if (position == pos) {
				Node* tmpNode = new Node;
				tmpNode->value = value;

				tmpNode->next = curNode->next;

				curNode->next = tmpNode;

				size_++;
				return;
			}

			pos++;
			curNode = curNode->next;
		}
	}

	int operator[] (const int index) {
		Node* curNode = first;
		int pos = 0;
		while (!(curNode == nullptr))
		{
			if (index == pos) {
				return curNode->value;
			}
			pos++;
			curNode = curNode->next;
		}

		std::cout << "Out of range";
	}

	int size() {
		return size_;
	}
};

int main()
{
	{
		Node* node = new Node;
		node->value = 5;

		node->next = new Node;
		node->next->value = 10;

		node->next->next = new Node;
		node->next->next->value = 15;

		node->next->next->next = nullptr;
	}

	{
		std::cout << "List from std:\n";
		std::forward_list<int> list;

		list.push_front(10);
		list.push_front(5);
		list.push_front(-19);

		list.pop_front();

		for (auto i : list) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}

	{
		std::cout << "Own list:\n";

		List list;

		list.push_front(10);
		list.push_front(5);
		list.push_front(-19);
		list.insert_after(2, 20);

		for (int i = 0; i < list.size(); ++i) {
			std::cout << list[i] << "\n";
		}

		list.print();

		std::cout << "List after clear:\n";
		list.clear();

		list.print();
	}
}*/