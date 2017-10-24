//============================================================================
// Name        :LinkedList.h
// Author      :Dr Fatma Serce
// Modified    :Shaila Hirji
// Copyright   : Your copyright notice
// Description : This class is a generic implementation of LinkedList using nodes
//              Modifications were made to this class by adding an :
//                                                      insert() function
//                                                      existing deleteNode() function was modified

//============================================================================
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

using namespace std;
template<class T>
struct node {
	T data;
	node *next;
};

template<class T>
class LinkedList {
private:
	LinkedList(const LinkedList &) = delete; //copy constructor

protected:
	int count;
	node<T> *head, *last;
public:
	LinkedList();

	bool isEmpty();

	int length();

	T front();

	T back();

	void insertFirst(T &);

	void insertLast(T &);

	//////////////my added functions
	virtual void insert(T &);

	virtual T deleteNode(T &);
	////////////////////////////

	void destroylist();

	LinkedList<T> &operator=(LinkedList<T> &);

	template<class U>
	friend ostream &operator<<(ostream &os, LinkedList<U> &list);

	virtual ~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList() {
	head = last = NULL;
	count = 0;
}

template<class T>
bool LinkedList<T>::isEmpty() {
	return head == NULL;
}

template<class T>
int LinkedList<T>::length() {
	return count;
}

template<class T>
T LinkedList<T>::front() {
	return head->data;
}

template<class T>
T LinkedList<T>::back() {
	return last->data;
}

template<class T>
void LinkedList<T>::insertFirst(T &item) {
	node<T> *temp = new node<T>;
	temp->data = item;
	temp->next = head;
	head = temp;
	count++;
	if (last == NULL)
		last = temp;

}

template<class T>
void LinkedList<T>::insertLast(T &item) {
	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = NULL;
	if (head == NULL) {
		head = last = newnode;
	} else {
		last->next = newnode;
		last = newnode;
	}
	count++;
}

///////////////// my edit /////////////////////////////////
template<class T>
void LinkedList<T>::insert(T &item) {
	insertLast(item); //calls insert last as the default insert method
}

template<class T>
T LinkedList<T>::deleteNode(T &item) {
	if (head == NULL) //check for empty list
		cerr << "empty list";
	else {
		if (head->data == item) { //if head is to be deleted
			node<T> *p = head;
			head = head->next;
			delete p;
			count--;
			if (head == NULL)
				last = NULL;
		} else {
			//two pointers to traverse list
			node<T> *p = head;
			node<T> *q = p->next;
			while (q != NULL && q->data != item) { //traverse through list to find desired node
				p = q;
				q = q->next;
			}
			if (q != NULL) { //item to be deleted was found, delete it
				p->next = q->next; //re assign p's next to node after q-- the node to be deleted
				count--; //decrement count
				if (last == q)
					last = p; //if node deleted was last node, reassign it
				delete q; //delete the node and free memory
			}
		}
	}
	return item; //return the node deleted
}
///////////////////////////////////////////////////////////////

template<class T>
void LinkedList<T>::destroylist() {
	node<T> *p;
	while (head != NULL) {
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &list) {
	if (this != &list) {
		copylist(list);
	}
	return *this;
}

template<class T>
ostream &operator<<(ostream &os, LinkedList<T> &list) {
	node<T> *p = list.head;
	while (p != NULL) {
		cout << p->data << " " << endl;
		p = p->next;
	}
	return os;
}

template<class T>
LinkedList<T>::~LinkedList() {
	destroylist();
}

#endif /* LINKEDLIST_H_ */
