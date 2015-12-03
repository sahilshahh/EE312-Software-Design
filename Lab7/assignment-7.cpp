/********************************************************************


********************************************************************/

#include "poly.h"

// Main function of your program - called by main
void runProgram()
{
	// repeatedly prompt the user and process the selected
	// operation until the user selects the quit option.
	int firstloop = 1;
	while (firstloop)
	{
		ifstream myfile;
		string numberoflines;
		string equations[1000];
		string fileinput;
		int number;
		string file;
		cout << "Enter the file that you would like to work with: ";
		cin >> file;
		myfile.open(file);
		if (myfile.is_open())
		{
			getline(myfile, numberoflines);
			number = atoi(numberoflines.c_str());
			for (int i = 0; i < number; i++)
			{
				getline(myfile, equations[i]);
			}
			myfile.close();
		}
		cout << "The polynomials available for operation are:" << endl;
		for (int i = 0; i < number; i++) {
			string option = to_string(i + 1);
			cout << option + ". " + equations[i] << endl;
		}
	SAME:
		cout << "What operation would you like to perform?" << endl;
		cout << "1. ADD polynomials" << endl;
		cout << "2. MULTIPLY polynomials" << endl;
		cout << "3. EVALUATE polynomial";
		cout << "\n" << endl;
		cout << "Enter choice #: ";
		char input;
		cin >> input;
		int poly1, poly2;
		myfile.open(file);
		switch (input)
		{
			//add polynomials
		case '1':
		{
			cout << "Enter the two polynomials that you would like to work with: ";
			scanf("%d,%d", &poly1, &poly2);
			myfile.clear();
			myfile.seekg(0);
			getline(myfile, fileinput);
			for (int a = 1; a < poly1; a++)
			{
				getline(myfile, fileinput);
			}
			getline(myfile, fileinput);
			char* cstr1 = &fileinput[0];
			Poly *p1 = new Poly(cstr1);
			for (int a = (poly1 + 1); a < poly2; a++)
			{
				getline(myfile, fileinput);
			}
			getline(myfile, fileinput);
			char* cstr2 = &fileinput[0];
			Poly *p2 = new Poly(cstr2);
			Poly p3 = *p1->add(*p2);
			cout << "The symbolic sum of the 2 polynomials is:" << endl;
			p3.print();
			delete p1;
			delete p2;
			break;
		}
		//multiply polynomials
		case '2':
		{
			cout << "Enter the two polynomials that you would like to work with: ";
			scanf("%d,%d", &poly1, &poly2);
			myfile.clear();
			myfile.seekg(0);
			getline(myfile, fileinput);
			for (int a = 1; a < poly1; a++)
			{
				getline(myfile, fileinput);
			}
			getline(myfile, fileinput);
			char* cstr1 = &fileinput[0];
			Poly *p1 = new Poly(cstr1);
			for (int a = (poly1 + 1); a < poly2; a++)
			{
				getline(myfile, fileinput);
			}
			getline(myfile, fileinput);
			char* cstr2 = &fileinput[0];
			Poly *p2 = new Poly(cstr2);
			Poly p3 = *p1->multiply(*p2);
			cout << "The symbolic product of the 2 polynomials is:" << endl;
			p3.print();
			delete p1;
			delete p2;
			break;
		}
		//evaluate polynomial
		case '3':
		{
			cout << "Enter the polynomial that you would like to work with: ";
			scanf("%d,%d", &poly1, &poly2);
			myfile.clear();
			myfile.seekg(0);
			getline(myfile, fileinput);
			for (int a = 1; a < poly1; a++)
			{
				getline(myfile, fileinput);
			}
			getline(myfile, fileinput);
			char* cstr1 = &fileinput[0];
			Poly *p1 = new Poly(cstr1);
			cout << "Enter the evaluation point (the value of x): ";
			double eval;
			scanf("%lf", &eval);
			double result = p1->eval(eval);
			printf("Value of that polynomial at %.1f is: %.1f", eval, result);
			printf("\n");
			printf("\n");
			delete p1;
			break;
		}
		}
		myfile.close();
	INPUT:
		cout << "Do you want to perform additional operations on the existing file (Y/N)? ";
		char answer1;
		cin >> answer1;
		if (answer1 == 'N' || answer1 == 'n')
		{
			cout << "Do you want to work with another file (Y/N)? ";
			char answer2;
			cin >> answer2;
			if (answer2 == 'N' || answer2 == 'n') {
				cout << "Thank you for using this program!";
				firstloop = 0;
			}
		}
		else if (answer1 == 'Y' || answer1 == 'y')
		{
			goto SAME;
		}
		else
		{
			cout << "Please enter a correct input";
			printf("\n");
			goto INPUT;
		}
	}
}

Poly::Poly(char* str)
{
	string str1 = str;
	istringstream buf(str1);
	istream_iterator<std::string> beg(buf), end;

	vector<string> tokens(beg, end); // done!

	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-")
		{
			continue;
		}
		struct Node* newnode = new Node;
		string look = tokens[i].substr(tokens[i].size() - 1);
		if (tokens.size() == 1)
		{
			newnode->degree = 0;
			string str4 = tokens[0];
			int value = atoi(str4.c_str());
			newnode->coeff = value;
			newnode->next = NULL;
			goto INSERT;
		}
		int temp = tokens[i].find('^') + 1;
		int tempCoeff = tokens[i].find('x');
		if (temp != 1 && temp != 0)
		{
			if (look == "-" || look == "+")
			{
				string str3 = tokens[i].substr(temp, tokens[i].size() - 1);
				int value = atoi(str3.c_str());
				newnode->degree = value;
			}
			else
			{
				string str3 = tokens[i].substr(temp);
				int value = atoi(str3.c_str());
				newnode->degree = value;
			}
		}
		// If there is an x
		else if (tempCoeff > 0)
		{
			newnode->degree = 1;
		}
		// If no x
		else
		{
			newnode->degree = 0;
		}

		// If no degree, just a constant
		if (newnode->degree == 0)
		{
			string str3 = tokens[i];
			double value = atoi(str3.c_str());
			if (tokens[i - 1] == "-")
			{
				value = value * (-1.0);
			}
			newnode->coeff = value;
		}

		// If there is a degree
		else
		{
			string str3 = tokens[i].substr(0, tempCoeff);
			double value = atoi(str3.c_str());
			if (i > 0)
			{
				string str1 = tokens[i - 1];
				string str2("-");
				if (str1.compare(str2) == 0)
				{
					value = value * (-1.0);
				}
			}
			newnode->coeff = value;
		}
		newnode->next = NULL;
	INSERT:
		if (i == 0)
		{
			p = newnode;

		}
		else
		{
			tempNod = p;
			while (tempNod->next)
			{
				tempNod = tempNod->next;
			}
			tempNod->next = newnode;
		}
	}
}

Poly::~Poly()
{
	Node* newTerm = p;
	Node* current = p;
	while (current != NULL)
	{
		current = current->next;
		delete newTerm;
		newTerm = current;
	}
}

Poly* Poly::add(Poly& otherPoly)
{
	string result;
	string degree = "x^";
	string normal = "x ";
	string plus = "+ ";
	string minus = "- ";
	string space = " ";
	int counter = 1;
	char numstr[21];
	int degree1;
	int degree2;

	struct Node* tempnode1 = new Node;
	tempnode1 = this->p;
	struct Node* tempnode2 = new Node;
	tempnode2 = otherPoly.p;

	while (!((tempnode1 == NULL) && (tempnode2 == NULL))) {
		//checks whether the node is NULL
		if (tempnode1 == NULL) {
			degree1 = -1;
		}
		else {
			degree1 = tempnode1->degree;
		}
		if (tempnode2 == NULL) {
			degree2 = -1;
		}
		else {
			degree2 = tempnode2->degree;
		}

		//if both degrees are same add them
		if (degree1 == degree2) {
			int sum = tempnode1->coeff + tempnode2->coeff;
			//checks to see if you need to print a + or - if the number isnt the first term
			if (sum > 0) {
				if (counter != 1) {
					result.append(plus);
					counter++;
				}
			}
			else if (sum < 0) {
				if (counter != 1) {
					result.append(minus);
					sum = sum *-1;
					counter++;
				}
			}
			else {
				counter--;
				goto SKIP;
			}
			result.append(itoa(sum, numstr, 10));
			//prints the approriate degree value
			if (tempnode1->degree == 1) {
				result.append(normal);
				//result.append(itoa(tempnode1->degree, numstr, 10));
				result.append(space);
			}
			else if (tempnode1->degree == 0) {
				//do nothing
			}
			else {
				result.append(degree);
				result.append(itoa(tempnode1->degree, numstr, 10));
				result.append(space);
			}
		SKIP:
			tempnode1 = tempnode1->next;
			tempnode2 = tempnode2->next;
			if (counter == 1) {
				counter++;
			}
		}

		//degree of 1 is bigger than 2
		else if (degree1 > degree2) {
			int sum = tempnode1->coeff;
			//checks to see if you need to print a + or - if the number isnt the first term
			if (sum > 0) {
				if (counter != 1) {
					result.append(plus);
					counter++;
				}
			}
			else if (sum < 0) {
				if (counter != 1) {
					result.append(minus);
					sum = sum *-1;
					counter++;
				}
			}
			else {
				counter--;
				goto SKIP1;
			}
			result.append(itoa(sum, numstr, 10));
			//prints the approriate degree value
			if (tempnode1->degree == 1) {
				result.append(normal);
				//result.append(itoa(tempnode1->degree, numstr, 10));
				result.append(space);
			}
			else if (tempnode1->degree == 0) {
				//do nothing
			}
			else {
				result.append(degree);
				result.append(itoa(tempnode1->degree, numstr, 10));
				result.append(space);
			}
		SKIP1:
			tempnode1 = tempnode1->next;
			if (counter == 1) {
				counter++;
			}
		}

		//degree 2 is greater than degree 1
		else {
			int sum = tempnode2->coeff;
			//checks to see if you need to print a + or - if the number isnt the first term
			if (sum > 0) {
				if (counter != 1) {
					result.append(plus);
					counter++;
				}
			}
			else if (sum < 0) {
				if (counter != 1) {
					result.append(minus);
					sum = sum *-1;
					counter++;
				}
			}
			else {
				counter--;
				goto SKIP2;
			}
			result.append(itoa(sum, numstr, 10));
			//prints the approriate degree value
			if (tempnode2->degree == 1) {
				result.append(normal);
				//result.append(itoa(tempnode2->degree, numstr, 10));
				result.append(space);
			}
			else if (tempnode2->degree == 0) {
				//do nothing
			}
			else {
				result.append(degree);
				result.append(itoa(tempnode2->degree, numstr, 10));
				result.append(space);
			}
		SKIP2:
			tempnode2 = tempnode2->next;
			if (counter == 1) {
				counter++;
			}
		}
	}

	char* resultstring = &result[0];
	Poly* resultpoly = new Poly(resultstring);
	return resultpoly;
}

Poly* Poly::multiply(Poly& otherPoly)
{
	string result;
	string degree = "x^";
	string normal = "x ";
	string plus = "+ ";
	string minus = "- ";
	string space = " ";
	int zerocheck = 0;
	int counter = 0;
	char numstr[21];
	int degree1;
	int degree2;
	double coEff1;
	double coEff2;
	int commonDegree[100] = { -1 };
	double commonCoeff[100];

	struct Node* tempnode1 = new Node;
	tempnode1 = this->p;
	struct Node* tempnode2 = new Node;
	tempnode2 = otherPoly.p;

	while (!(tempnode1 == NULL))
	{
		degree1 = tempnode1->degree;  // Gets the degree of first poly
		coEff1 = tempnode1->coeff;    // Gets the coefficient of first poly
		tempnode2 = otherPoly.p;
		if (coEff1 == 0)
		{
			zerocheck = 1;
			commonCoeff[0] = 0;
			goto zero;
		}
		while (!((tempnode2 == NULL)))
		{
			degree2 = tempnode2->degree;  // Degree of Poly 2
			coEff2 = tempnode2->coeff;    // Coeff of Poly 2
			if (coEff2 == 0)
			{
				zerocheck = 1;
				commonCoeff[0] = 0;
				goto zero;
			}
			double mulCoeff = coEff1 * coEff2;   // Multiplies the coeff
			int mulDegree = degree1 + degree2;   // Adds the degree
			if (mulCoeff == 0)
			{
				goto SKIP;   //  If it's equal to 0, then just move onto next set
			}
			else
			{
				int x = find(commonDegree, counter, mulDegree);  // Checks if the degree is similar
				if (x == -1)  // No similar degrees
				{
					commonDegree[counter] = mulDegree;  // Adds to array
					commonCoeff[counter] = mulCoeff;   // Adds to array
					counter++;  // Tracks the size of array
				}
				else
				{
					// If there is a common degree, add the coefficients in that array spot
					commonCoeff[x] = commonCoeff[x] + mulCoeff;
				}
			}

		SKIP:
			tempnode2 = tempnode2->next;
		}
		tempnode1 = tempnode1->next;
	}
	double temp = 0.0;
	// Sorts the array so that the highest degree first, sorts commonCoeff the same so they'll have same spot
	for (int j = 0; j < counter - 1; j++)
	{
		if (commonDegree[j] == -1)
		{
			break;
		}
		for (int i = j + 1; i < counter; i++)
		{
			if (commonDegree[i] == -1)
			{
				break;
			}
			else if (commonDegree[j] < commonDegree[i])
			{
				temp = commonDegree[j];
				commonDegree[j] = commonDegree[i];
				commonDegree[i] = temp;
				temp = commonCoeff[j];
				commonCoeff[j] = commonCoeff[i];
				commonCoeff[i] = temp;

			}
		}
	}
	// Makes the statement to print out 
	int firstcounter = 1;
	for (int k = 0; k < counter; k++)
	{
		if (commonCoeff[k] == 0)
		{
			continue;
		}
		result.append(itoa(commonCoeff[k], numstr, 10));
		if (commonDegree[k] == 1)
		{
			result.append(normal);
		}
		else if (commonDegree[k] > 1)
		{
			result.append(degree);
			result.append(itoa(commonDegree[k], numstr, 10));
		}
		if (k == counter - 1)
		{
			continue;
		}
		else {
			result.append(plus);
		}
	}
zero:
	if (zerocheck == 1)
	{
		result.append(itoa(commonCoeff[0], numstr, 10));
	}
	char* resultstring = &result[0];
	Poly* resultpoly = new Poly(resultstring);
	return resultpoly;
}

double Poly::eval(double x)
{
	double result = 0;
	struct Node* tempnode1 = new Node;
	tempnode1 = this->p;
	//computes the value of each term
	while (tempnode1)
	{
		double power = pow(x, tempnode1->degree);
		double term = tempnode1->coeff * power;
		result = result + term;
		tempnode1 = tempnode1->next;
	}
	return result;
}

void Poly::print()
{
	Node *current = this->p;
	if (!current)
	{
		printf("0\n");
		return;
	}
	if (current->degree == 0)
	{
		printf("%.1lf", current->coeff);
	}
	else if (current->degree == 1)
	{
		printf("%.1lfx", current->coeff);
	}
	else {
		printf("%.1lfx^%d", current->coeff, current->degree);
	}
	current = current->next;
	while (current)
	{
		printf(" + ");
		if (current->degree == 0)
		{
			printf("%.1lf", current->coeff);
		}
		else if (current->degree == 1)
		{
			printf("%.1lfx", current->coeff);
		}
		else
		{
			printf("%.1lfx^%d", current->coeff, current->degree);
		}
		current = current->next;
	}
	printf("\n");
	printf("\n");
}

bool Poly::equals(Poly& otherPoly)
{
	struct Node* tempnode1 = new Node;
	tempnode1 = this->p;
	struct Node* tempnode2 = new Node;
	tempnode2 = otherPoly.p;
	bool answer;
	int counter1 = 0;
	int counter2 = 0;
	while (!(tempnode1 == NULL || tempnode2 == NULL))
	{
		if (tempnode1->coeff == tempnode2->coeff)
		{
			if (tempnode1->degree == tempnode2->degree)
			{
			}
			else
			{
				goto BREAK;
			}
		}
		else
		{
			goto BREAK;
		}
		tempnode1 = tempnode1->next;
		tempnode2 = tempnode2->next;
	}
	if (tempnode1 == NULL && tempnode2 == NULL)
	{
		answer = true;
		goto END;
	}
BREAK:
	answer = false;
END:
	return answer;
}

int Poly::find(int arr[], int len, int seek)
{
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == seek)
		{
			return i;
		}
	}
	return -1;
}