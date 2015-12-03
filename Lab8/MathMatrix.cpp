#include "MathMatrix.h"
using namespace std;

MathMatrix::MathMatrix()
{
	vector <int> row;
	row.push_back(0);
	matrix.push_back(row);
}

MathMatrix::MathMatrix(int numRows, int numCols, int** mat)
{
	for (int i = 0; i < numRows; i++) {
		vector<int> row; // Create an empty row
		for (int j = 0; j < numCols; j++) {
			row.push_back(mat[i][j]); // Add an element (column) to the row
		}
		matrix.push_back(row); // Add the row to the main vector
	}
}

MathMatrix::MathMatrix(const vector<vector<int>>& mat)
{
	matrix = mat;
}

MathMatrix::MathMatrix(int numRows, int numCols, int initialValue)
{
	for (int i = 0; i < numRows; i++) {
		vector<int> row; // Create an empty col
		for (int j = 0; j < numCols; j++) {
			row.push_back(initialValue); // Add an element (column) to the row
		}
		matrix.push_back(row); // Add the row to the main vector
	}
}

MathMatrix::~MathMatrix()
{
	/*TODO: ADD YOUR CODE HERE*/
}

void MathMatrix::changeElement(int row, int col, int newValue)
{
	vector <int> row1 = matrix[row];
	row1[col] = newValue;
	matrix[row] = row1;
	return;
}
int MathMatrix::numRows() const
{
	int i = matrix.size();
	return i;
}
int MathMatrix::numCols() const
{
	vector <int> row = matrix[0];
	int j = row.size();
	return j;
}
int MathMatrix::getVal(int row, int col)
{
	vector <int> row1 = matrix[row];
	int value = row1[col];
	return value;
}
MathMatrix MathMatrix::add(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	MathMatrix right;
	right = rightHandSide;
	if ((this->numCols() != right.numCols()) || (this->numRows() != right.numRows())) {
		return result;
	}
	else {
		int** newmat = new int*[this->numRows()];
		for (int i = 0; i < this->numRows(); i++) {
			newmat[i] = new int[this->numCols()];
			for (int j = 0; j < this->numCols(); j++) {
				newmat[i][j] = this-> getVal(i,j)+right.getVal(i,j);
			}
		}
		MathMatrix answer(this->numRows(), this->numCols(), newmat);
		return answer;
	}
}
MathMatrix MathMatrix::subtract(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	MathMatrix right;
	right = rightHandSide;
	if ((this->numCols() != right.numCols()) || (this->numRows() != right.numRows())) {
		return result;
	}
	else {
		int** newmat = new int*[this->numRows()];
		for (int i = 0; i < this->numRows(); i++) {
			newmat[i] = new int[this->numCols()];
			for (int j = 0; j < this->numCols(); j++) {
				newmat[i][j] = this->getVal(i, j) - right.getVal(i, j);
			}
		}
		MathMatrix answer(this->numRows(), this->numCols(), newmat);
		return answer;
	}
}
MathMatrix MathMatrix::multiply(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	MathMatrix right;
	right = rightHandSide;
	if (this->numCols() != right.numRows()) {
		return result;
	}
	else {
		int** newmat = new int*[this->numRows()];
		for (int i = 0; i < this->numRows(); i++) {
			newmat[i] = new int[right.numCols()];
			for (int j = 0; j < right.numCols(); j++) {
				newmat[i][j] = 0;
				for (int k = 0; k < this->numCols(); k++) {
					newmat[i][j] += this->getVal(i, k) * right.getVal(k, j);
				}
			}
		}
		MathMatrix answer(this->numRows(), right.numCols(), newmat);
		return answer;
	}
}

bool MathMatrix::equals(const MathMatrix& rightHandSide)
{
	MathMatrix right;
	right = rightHandSide;
	if ((this->numCols() != right.numCols()) || (this->numRows() != right.numRows())) {
		goto END;
	}
	else {
		for (int i = 0; i < this->numRows(); i++) {
			for (int j = 0; j < this->numCols(); j++) {
				if (this->getVal(i, j) != right.getVal(i, j)) {
					goto END;
				}
			}
		}
		return true;
	}
	END:
	return false;
}

MathMatrix MathMatrix:: operator+(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	MathMatrix right;
	right = rightHandSide;
	if ((this->numCols() != right.numCols()) || (this->numRows() != right.numRows())) {
		return result;
	}
	else {
		int** newmat = new int*[this->numRows()];
		for (int i = 0; i < this->numRows(); i++) {
			newmat[i] = new int[this->numCols()];
			for (int j = 0; j < this->numCols(); j++) {
				newmat[i][j] = this->getVal(i, j) + right.getVal(i, j);
			}
		}
		MathMatrix answer(this->numRows(), this->numCols(), newmat);
		return answer;
	}
}

MathMatrix MathMatrix:: operator-(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	MathMatrix right;
	right = rightHandSide;
	if ((this->numCols() != right.numCols()) || (this->numRows() != right.numRows())) {
		return result;
	}
	else {
		int** newmat = new int*[this->numRows()];
		for (int i = 0; i < this->numRows(); i++) {
			newmat[i] = new int[this->numCols()];
			for (int j = 0; j < this->numCols(); j++) {
				newmat[i][j] = this->getVal(i, j) - right.getVal(i, j);
			}
		}
		MathMatrix answer(this->numRows(), this->numCols(), newmat);
		return answer;
	}
}
MathMatrix MathMatrix:: operator*(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	MathMatrix right;
	right = rightHandSide;
	if (this->numCols() != right.numRows()) {
		return result;
	}
	else {
		int** newmat = new int*[this->numRows()];
		for (int i = 0; i < this->numRows(); i++) {
			newmat[i] = new int[right.numCols()];
			for (int j = 0; j < right.numCols(); j++) {
				newmat[i][j] = 0;
				for (int k = 0; k < this->numCols(); k++) {
					newmat[i][j] += this->getVal(i, k) * right.getVal(k, j);
				}
			}
		}
		MathMatrix answer(this->numRows(), right.numCols(), newmat);
		return answer;
	}
}

bool MathMatrix:: operator==(const MathMatrix& rightHandSide)
{
	MathMatrix right;
	right = rightHandSide;
	if ((this->numCols() != right.numCols()) || (this->numRows() != right.numRows())) {
		goto END;
	}
	else {
		for (int i = 0; i < this->numRows(); i++) {
			for (int j = 0; j < this->numCols(); j++) {
				if (this->getVal(i, j) != right.getVal(i, j)) {
					goto END;
				}
			}
		}
		return true;
	}
END:
	return false;
}

MathMatrix MathMatrix::scale(int factor)
{
	int** newmat = new int*[this->numRows()];
	for (int i = 0; i < this->numRows(); i++) {
		newmat[i] = new int[this->numCols()];
		for (int j = 0; j < this->numCols(); j++) {
			newmat[i][j] = this->getVal(i, j) * factor;
		}
	}
	MathMatrix answer(this->numRows(), this->numCols(), newmat);
	return answer;
}
MathMatrix MathMatrix::getTranspose()
{
	/*TODO: ADD YOUR CODE HERE*/
	int** newmat = new int*[this->numRows()];
	for (int i = 0; i < this->numRows(); i++) {
		newmat[i] = new int[this->numCols()];
		for (int j = 0; j < this->numCols(); j++) {
			newmat[i][j] = this->getVal(i, j);
		}
	}

	int** newmat1 = new int*[this->numCols()];
	for (int i = 0; i < this->numCols(); i++) {
		newmat1[i] = new int[this->numRows()];
		for (int j = 0; j < this->numRows(); j++) {
			newmat1[i][j] = newmat[j][i];
		}
	}

	MathMatrix answer(this->numCols(), this->numRows(), newmat1);
	return answer;
}