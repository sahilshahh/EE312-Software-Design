
#include "assignment-5_calculator.h"
#include "assignment-5_logMgr.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void logMgr_tests();
void calculator_tests();

int main() {
	calculator_tests();
	logMgr_tests();
	/*
	Stack* stk = initialize_stk();
	push(stk, 4.0);
	printStack(stk);
	push(stk, 5.0);
	printStack(stk);
	push(stk, 6.0);
	printStack(stk);
	int searching = search(stk, 7.0);
	int testsize = size(stk);
	double peeker = peek(stk);
	double popped = pop(stk);
	printStack(stk);
	popped = pop(stk);
	printStack(stk);
	testsize = size(stk);
	peeker = peek(stk);

	Queue* queue = initialize_q();
	enqueue(queue, 10);
	printQueue(queue);
	insert(queue, 3, 0);
	printQueue(queue);
	enqueue(queue, 5);
	printQueue(queue);
	enqueue(queue, 13);
	printQueue(queue);
	long first = dequeue(queue);
	printQueue(queue);
	*/

	return 0;
}

void calculator_tests() {
    char expr1[][MAX_EXPR_LENGTH] = {"2", "-2", "+"};
    char expr2[][MAX_EXPR_LENGTH] = {"2", "2", "+", "3", "*"};
	char expr3[][MAX_EXPR_LENGTH] = {"4.876555", "7", "3", "+", "*"};
	
	printf("expr1 = %lf \n", eval( expr1, sizeof(expr1)/sizeof(expr1[0]) ) );
    	assert( eval( expr1, sizeof(expr1)/sizeof(expr1[0]) ) == 0 );
	
	printf("expr2 = %lf \n", eval( expr2, sizeof(expr2)/sizeof(expr2[0]) ) );
    	assert( eval( expr2, sizeof(expr2)/sizeof(expr2[0]) ) == 12 );

	printf("expr3 = %lf \n", eval( expr3, sizeof(expr3)/sizeof(expr3[0]) ) );
    	assert( eval( expr3, sizeof(expr3)/sizeof(expr3[0]) ) == 48.76555 );
    
	printf("All tests passed successfully :-) \n");
}


#define WINDOW_SIZE 2

void logMgr_tests() {
    log_manager *log = createLogMgr( WINDOW_SIZE );
    assert( add_to_log( log, 1 ) == 1 );
    assert( add_to_log( log, 2 ) == 2 );
    assert( add_to_log( log, 3 ) == 3 );
    assert( add_to_log( log, 4 ) == 3 );
    assert( add_to_log( log, 4 ) == 4 );
    assert( add_to_log( log, 10 ) == 1 );
    
	printf("All tests passed successfully :-) \n");
	getchar();
}