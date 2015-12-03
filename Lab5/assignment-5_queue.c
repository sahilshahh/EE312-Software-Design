#include "assignment-5_queue.h"
#include <stdlib.h>
#include <stdio.h>

/* Your queue implementations here */

Queue* initialize_q() {									//work
	Queue *newqueue = (Queue*)malloc(sizeof(Queue));
	newqueue->size = 0;
	newqueue->head = NULL;
	newqueue->tail = NULL;
	return newqueue;

}

void enqueue(Queue* my_Q, long elt) {					//work
	Node_q *temp = (Node_q*)malloc(sizeof(Node_q));
	temp->data = elt;
	temp->next = NULL;
	if (my_Q->head == NULL && my_Q->tail == NULL) {
		my_Q->head = my_Q->tail = temp;
		my_Q->size++;
		return;
	}
	else {
		my_Q->tail->next = temp;
		my_Q->tail = temp;
	}
	my_Q->size++;
}

long dequeue(Queue* my_Q) {								//work
	Node_q *temp;
	temp = my_Q->head;
	if (my_Q->head == NULL) {
		return -1;   //what do give if nothings in?
	}
	else if (my_Q->head == NULL && my_Q->tail == NULL) {
		long data = my_Q->head->data;
		my_Q->head = my_Q->tail = NULL;
		my_Q->size--;
		free(temp);
		return data;
	}
	else {
		long data = my_Q->head->data;
		my_Q->head = my_Q->head->next;
		my_Q->size--;
		free(temp);
		return data;
	}
	
}

void insert(Queue* my_Q, long elt, int index) {			//
	Node_q* newnode = (Node_q*)malloc(sizeof(Node_q));
	newnode->data = elt;
	Node_q* temp;
	Node_q* temp1;
	if (index < 0 ||(index > my_Q->size)) {
		return;
	}
	if (index == 0) {
		long array[500];
		int z = my_Q->size;
		for (int i = 0; i < z; i++) {
			array[i] = dequeue(my_Q);
		}
		my_Q->head = NULL;
		my_Q->tail = NULL;
		enqueue(my_Q, elt);
		for (int i = 0; i < z; i++) {
			enqueue(my_Q, array[i]);
		}
		return;
	}
	temp = my_Q->head;
	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}
	temp1 = temp->next;
	temp->next = newnode;
	newnode->next = temp1;	
	my_Q->size++;
}

void printQueue(Queue* my_Q) {							//work
	Node_q* temp;
	temp = my_Q->head;
	while (temp != NULL) {
		int data = temp->data;
		temp = temp->next;
		if (temp != NULL) {
			printf("%d, ", data);
		}
		else {
			printf("%d", data);
		}
	}
	printf("\n");
}
