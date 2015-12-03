#include "assignment-5_stack.h"
#include <stdlib.h>
#include <stdio.h>

/* Your stack implementations here */

Stack* initialize_stk() {							//work
	Stack *newstack;
	newstack = (Stack*)malloc(sizeof(Stack));
	newstack -> size = 0;
	newstack->top = NULL;
	return newstack;
}

int size(Stack* stk) {								//work
	return stk->size;
}

void push(Stack* stk, double data) {				//work
	Node_s *new;
	new = (Node_s*)malloc(sizeof(Node_s));
	new->data = data;
	new->next = stk->top;
	stk->top = new;
	stk->size++;
}

double pop(Stack* stk) {							//work
	Node_s *temporary;
	if (stk->size == 0) {
		return -1;				//what do you do if theres nothing in stack
	}
	double temp = stk->top->data;
	temporary = stk->top;
	stk->top = stk->top->next;
	free(temporary);
	stk->size--;
	return temp;
}

double peek(Stack* stk) {							//work
	return stk->top->data;
}

int search(Stack* stk, double data) {				//work
	Node_s *temporary;
	temporary = stk->top;
	int counter = 1;
	while (counter <= stk->size) {
		if (temporary->data == data) {
			return stk->size + 1 - counter;
		}
		counter++;
		temporary = temporary->next;
	}
	return(0);
}

void printStack(Stack* stk) {						//work
	Node_s *temp;
	temp = stk->top;
	while (temp != NULL) {
		double data = temp->data;
		temp = temp->next;
		if (temp != NULL) {
			printf("%lf, ", data);
		}
		else {
			printf("%lf", data);
		}
	}
	printf("\n");
}