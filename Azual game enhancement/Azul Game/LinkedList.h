#pragma once
#ifndef _LIST_H_
#define _LIST_H_

struct Node {
	char data;
	Node* next;
	Node* prev;
};

class Linkedlist {
public:
	Linkedlist();
	~Linkedlist();

	// Insert a Node to tail
	void insertTail(char data);

	// Remove Given-data Node in list
	void removeNode(char data);

	// Printing the linkedlist.
	void printList();

	// Get size
	int GetSize();

	// Remove 1 node from tail
	void remove1Node_from_tail();

	// Clear the list
	void Clear_List();

private:
	//size of linked list
	int max = 7;
	int size = 0;
	Node* head;
	Node* tail;

};

#endif