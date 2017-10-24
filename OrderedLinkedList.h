//============================================================================
// Name        :OrderedLinkedList.h
// Author      :Shaila Hirji
// Version     :
// Copyright   : Your copyright notice
// Description :This class is a generic derived(inhertied) from LinkedLinked class (base class)
//             : The purpose of this class is to provide an Ordered-Linked List
//             : It overides 2 funtcions of LinkedList class -insert and deleteNode
//             : It contains one new function, the search function
//============================================================================
#ifndef ORDEREDLINKEDLIST_CPP_
#define ORDEREDLINKEDLIST_CPP_

#include "LinkedList.h"
#include "Passenger.h"

using namespace std;

template<class T>
class OrderedLinkedList: public LinkedList<T> {

public:
	void insert(T &);

	T deleteNode(T &);

	T search(T);

};

/*
 * This method adds items to the LinkedList in ascending order
 */
template<class T>

void OrderedLinkedList<T>::insert(T &item) {

	node<T> *newNode = new node<T>; //for storing new data
	newNode->data = item; //assign item to new node
	node<T> *head = OrderedLinkedList<T>::head; //pointer to list's head
	node<T> *last = OrderedLinkedList<T>::last; //pointer list's last

	//if item already exists as head or last, print message
	if (!OrderedLinkedList<T>::isEmpty()
			&& (newNode->data == head->data || newNode->data == last->data)) {
		cout << "Passenger already exists" << endl;
		return; //break
	}

	//if empty list, just add the new node

	if (OrderedLinkedList<T>::isEmpty()) {

		//assign head and last to the new node
		head = last = newNode;
		newNode->next = NULL;

		//reassign list's head and last
		OrderedLinkedList::head = head;
		OrderedLinkedList::last = last;
		OrderedLinkedList<T>::count++;

	} else { //if list isn't empty

		//if new item larger than item at the end of the list and the item doesnt already exist
		if (newNode->data > last->data) {
			OrderedLinkedList<T>::insertLast(newNode->data); //add item to end of list
		}

		//if new item is smaller than the data in the existing head and item doesnt already exists

		else if (newNode->data < head->data) {
			OrderedLinkedList<T>::insertFirst(newNode->data); //add new node as the head

		} else {

			//new node's data is in between head and last values

			node<T> *pCurrent = head; //points to head, used for traversing

			while (pCurrent != NULL) {
				//check two node's per traversal, current and current's next
				//if current and current's next item both are less than the new item, move pCurrent forward

				if (pCurrent->data < newNode->data && pCurrent->next != NULL
						&& pCurrent->next->data < newNode->data) {

					pCurrent = pCurrent->next;               //move to next item

				} else if (pCurrent->next != NULL
						&& pCurrent->next->data == newNode->data) { //item already exists

					cout << "Passenger already exists" << endl;

					break;
				}

				//if item is greater than data in current node but less than in the node next to current, add item after current, before current's next
				newNode->next = pCurrent->next;
				pCurrent->next = newNode;

				if (head == last) { //if the head and last point to same node, reassign last node and set new node's next to null
					newNode->next = NULL;
					LinkedList<T>::last = last = newNode;
				}
				pCurrent = NULL; //flag to exit while loop, item already added
				OrderedLinkedList<T>::count++; //update count
			}
		}
	}

}

/*
 * This function delete's nodes in the linked list
 * returns the node that was deleted
 */
template<class T>

T OrderedLinkedList<T>::deleteNode(T &item) {

	if (!LinkedList<T>::isEmpty()) { //if list isn't empty

		//if item isn't the data in head and it is less than head's data
		if (item != LinkedList<T>::head->data
				&& item < LinkedList<T>::head->data) {
			cout << " Passenger has no bookings" << endl; //item doesnt exist

		} else { //search list and delete item if available

			node<T> *head = LinkedList<T>::head; //point to list's head
			node<T> *last = LinkedList<T>::last; //point to list's last

			//first item is item to be deleted
			if (head->data == item) {
				node<T> *p = head;
				item = head->data; //re assign item to get full details of passenger
				LinkedList<T>::head = head = head->next; //reassign head
				delete p;
				LinkedList<T>::count--;
				return item;

				if (head == NULL)
					last = NULL; //if there was only one node and now ,we deleted it, make last null
			} else {
				node<T> *p = head; //points to head node , used for traversal
				node<T> *q = p->next; //points to head's next, used for traversal
				while (q != NULL && q->data != item) { //while item to be deleted not found , traverse
					p = q;
					q = q->next;
				}
				if (q != NULL && q->data == item) { //item to de deleted found
					p->next = q->next;
					if (last == q) {
						LinkedList<T>::last = last = p; //re assign last
					}
					item = q->data; //re assign item to get full details of item
					delete q;
					LinkedList<T>::count--;
					return item;
				}
			}

			//passenger not found
			cout << "Passenger has no bookings" << endl;
		}

	}
	return item;
}

/*
 * This function searches for specific item in the list
 * returns the item once its found
 */
template<class T>
T OrderedLinkedList<T>::search(T item) {

	node<T> *pointer = LinkedList<T>::head; // pointer to head of list

	//if head is greater than item to be searched, no need to search list, the item doesnt exist

	if (!LinkedList<T>::isEmpty() && pointer->data > item) {
		return item;
	}

	//find the desired item
	while (!LinkedList<T>::isEmpty() && pointer != NULL) {

		if (pointer->data == item) {
			return pointer->data; //returns item with all details
		} else {
			pointer = pointer->next; //traverse
		}
	}

	return item;

}

#endif /* ORDEREDLINKEDLIST_CPP_ */
