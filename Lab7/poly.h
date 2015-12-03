/********************************************************************

********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct Node
{
	double coeff;
	int degree;
	Node* next;
} Node;

// function where the interactive menu should be implemented
void runProgram();

class Poly
{
private:
	// add private members as needed
	struct Node* p = new Node;
	struct Node* tempNod = new Node;
	Node* polynomial;
	int degrees;
public:
	Poly(char* str);
	~Poly();
	Poly* add(Poly& otherPoly);
	Poly* multiply(Poly& otherPoly);
	double eval(double x);
	void print();
	bool equals(Poly& otherPoly);
	// add public members if needed
	int find(int arr[], int len, int seek);
};