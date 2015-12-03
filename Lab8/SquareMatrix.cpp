#include "SquareMatrix.h"
using namespace std;

SquareMatrix::SquareMatrix()
{
	/*TODO: ADD YOUR CODE HERE*/
	vector <int> row;
	row.push_back(0);
	matrix.push_back(row);
}

SquareMatrix::SquareMatrix(int size, int initialValue)
{
	/*TODO: ADD YOUR CODE HERE*/
	for (int i = 0; i < size; i++)
	{
		vector<int> row; // Create an empty col
		for (int j = 0; j < size; j++)
		{
			row.push_back(initialValue); // Add an element (column) to the row
		}
		matrix.push_back(row); // Add the row to the main vector
	}
}

SquareMatrix::~SquareMatrix()
{
	/*TODO: ADD YOUR CODE HERE*/
}

SquareMatrix SquareMatrix::createIdentityMatrix(int size)
{
	/*TODO: ADD YOUR CODE HERE*/
	SquareMatrix result(size, 0);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				result.changeElement(i, j, 1);
			}
			else
			{
				result.changeElement(i, j, 0);
			}
		}
	}
	return result;
}

int SquareMatrix::getDeterminant()
{
	/*TODO: ADD YOUR CODE HERE*/
	int size = this->numRows();
	if (size == 2)
	{
		int first = this->getVal(0, 0);
		int second = this->getVal(0, 1);
		int third = this->getVal(1, 0);
		int fourth = this->getVal(1, 1);

		return ((first * fourth) - (second * third));
	}
	else if (size == 3)
	{
		int first = this->getVal(0, 0);
		int second = this->getVal(0, 1);
		int third = this->getVal(0, 2);
		int fourth = this->getVal(1, 0);
		int fifth = this->getVal(1, 1);
		int sixth = this->getVal(1, 2);
		int seventh = this->getVal(2, 0);
		int eighth = this->getVal(2, 1);
		int ninth = this->getVal(2, 2);

		return (first * ((fifth * ninth) - (sixth * eighth))) - (second * ((fourth * ninth) - (sixth * seventh))) + (third * ((fourth * eighth) - (fifth * seventh)));

	}
	else
	{
		return 0;
	}
}

bool SquareMatrix::isSymmetric()
{
	/*TODO: ADD YOUR CODE HERE*/
	if ((this->numRows()) == (this->numCols()))
	{
		int size = this->numRows();
		SquareMatrix temp(size, 0);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				temp.changeElement(i, j, (this->getVal(i, j)));
			}
		}

		for (int c = 0; c < size; c++)
		{
			for (int d = 0; d < size; d++)
			{
				if (temp.getVal(c, d) != temp.getTranspose().getVal(c, d))
				{
					goto Notsem;
				}
			}
		}
		return true;
	}
Notsem:
	return false;
}