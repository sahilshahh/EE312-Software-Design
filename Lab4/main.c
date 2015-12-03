#include <stdio.h>

/************************************************************/
/* Do NOT change the arguments of this prototype declaration.*/
extern int match(char *s, char *r);
/************************************************************/
/************************************************************/


/************************************************************/
/* This function calls match for each test case passed from main.*/
/************************************************************/

int test(char *s, char *r, int expectedResult) {
	if (expectedResult != match(s, r)) {
		printf("Failed test: match(%s,%s)\n", s, r);
	}
	else {
		printf("Passed test: match(%s,%s)\n", s, r);

	}
	return 0;
}
/************************************************************/
/************************************************************/


/************************************************************/
/* The main function calls the test function with each test case.*/
/************************************************************/
int main(void) {
	test("", "", 1);
	test("ag", "a.", 1);
	test("tc", ".t", 0);
	test("cccgat", "c*gat", 1);
	test("tc", "c*t*c", 1);
	test("c", ".", 1);
	test("cc", "c", 0);
	test("ac", ".*c", 1);
	test("acac", ".*a.*", 1);
	test("", ".*", 1);

	getchar();

	return 0;
}
/************************************************************/
/************************************************************/

