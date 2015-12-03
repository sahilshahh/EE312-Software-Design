#include "MathMatrix.h"
using namespace std;

int main()
{
	/* 
		Add code here to test the functionality of your
		classes.
	*/
	MathMatrix math;
	int** newmat = new int*[3];
	for (int i = 0; i < 3; i++) {
		newmat[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			newmat[i][j] = 7;
		}
	}
	MathMatrix matrix(3, 3, newmat);
	MathMatrix matrixsame(3, 3, newmat);
	MathMatrix matrix2(3, 3, 2);
	MathMatrix matrix1(2, 3, 2);
	matrix1.changeElement(1, 1, 1);
	int i = matrix1.numRows();
	int j = matrix1.numCols();
	int x = matrix1.getVal(1, 1);
	MathMatrix matrix3 = matrix.add(matrix2);
	MathMatrix matrix3a = matrix + matrix2;
	MathMatrix matrix4 = matrix.subtract(matrix2);
	MathMatrix matrix4a = matrix - matrix2;
	MathMatrix matrix5 = matrix.multiply(matrix2);
	MathMatrix matrix5a = matrix * matrix2;
	bool answer = matrix.equals(matrixsame);
	bool answer1 = matrix == matrixsame;
	MathMatrix matrix6 = matrix.scale(3);
	MathMatrix matrix7 = matrix1.getTranspose();
	return 0;
}