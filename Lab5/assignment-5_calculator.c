#include "assignment-5_calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// code for eval should allocate an operand_stack (declared in assignment-5_calculator.h)
// and push operands into the stack, and pop arguments when operator is encountered
// e.g. 2 2 + 3 *
// [] -> [2] -> [2,2] -> [2] - > [] -> [4] -> [4,3] -> [4] -> [] -> [7]
// return the last value in the stack
// if size > 1 when done, assert an error


double eval(char expr[][MAX_EXPR_LENGTH], int N)
{

	Stack* stk = initialize_stk();

	int i;
	for (i = 0; i < N; i++)
	{
		double num = 0;
		int count = 1;
		int decimal = 0;
		char c = expr[i][0];
		if (c == '-') {
			if (expr[i][1] != NULL) {
				double number = atof(expr[i]);
				push(stk, number);
			}
			else {
				double value1 = (double)pop(stk);
				double value2 = (double)pop(stk);
				double results = 0;
				switch (c)
				{
				case '-': results = value1 - value2; break;
				}
				push(stk, results);
			}
		}
		else if (c == '*' || c == '/' || c == '+')
		{
			double operand2 = (double)pop(stk);
			double operand1 = (double)pop(stk);
			double result = 0;

			switch (c)
			{
			case '*': result = operand2 * operand1; break;
			case '/': result = operand2 / operand1; break;
			case '+': result = operand2 + operand1; break;
			}

			push(stk, result);
		}

		else
		{
			num = atof(expr[i]);
			push(stk, num);
		}
	}

	return pop(stk);
}
