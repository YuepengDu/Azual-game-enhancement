#include "Linkedlist.h"
#include <iostream>

Linkedlist::Linkedlist() {
	head = nullptr;
	tail = nullptr;
}
Linkedlist::~Linkedlist() {
	Node*tmp;
	while (head != nullptr)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

// Get the size of list
int Linkedlist::GetSize() {
	return this->size;
}

// Insert a Node to tail
void Linkedlist::insertTail(char data) {
	if (this->size == this->max) {
		std::cout << std::endl << "Cannot push more tiles to broken line" << std::endl;
		return;
	}

	if (head == nullptr)
	{
		head = new Node;
		head->data = data;
		tail = head;
		head->next = nullptr;
		size++;
	}
	else
	{
		// create a new node
		Node *cur = head;
		// Loop the list to the end node
		while (cur->next != nullptr)
			cur = cur->next;
		// Create a new node
		Node *p = new Node;
		// Get the data to the node
		p->data = data;
		// new node now is the new tail
		tail = p;
		p->next = nullptr;
		// get the connection to the previous code
		p->prev = cur;
		cur->next = p;
		size++;
	}
}

// Remove Given-data Node in list
void Linkedlist::removeNode(char data) {
	if (head == nullptr) {
		return;
	}
	while (head->data == data) {
		Node*tmp = head;
		head = head->next;
		delete tmp;
		this->size--;
	}
	Node*cur = head;
	while (cur != nullptr) {
		if (cur->data == data) {
			// point to current position
			Node*tmp = cur;
			// go back 1 node
			cur = cur->prev;
			// get the connection to next Node
			if (tmp->next == nullptr) {
				cur->next = nullptr;
			}
			else {
				cur->next = tmp->next;
				// get the connection backward from next Note
				Node*tmp_next = tmp->next;
				tmp_next->prev = cur;
				
			}
			delete tmp;
			this->size--;
		}
		cur = cur->next;
	}
}

void Linkedlist::remove1Node_from_tail() {
	// if there is no data in list
	if (this->head == nullptr)
		return;
	if (this->head->next == nullptr) {
		Node *tmp = this->head;
		this->head = nullptr;
		delete tmp;
		this->size--;
		return;
	}
	// point to the last element of list
	Node*tmp = this->tail;
	// move Tail to previous element
	this->tail = this->tail->prev;
	this->tail->next = nullptr;
	this->size--;
	delete tmp;
}

void Linkedlist::printList() {
	if (this->head == nullptr) {
		std::cout << "Empty" << std::endl;
	}

	Node*cur = head;
	while (cur != nullptr) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}
}

void Linkedlist::Clear_List() {
	Node*tmp;
	while (head != nullptr)
	{
		tmp = head;
		head = head->next;
		delete tmp;
		this->size--;
	}
	this->size = 0;
}