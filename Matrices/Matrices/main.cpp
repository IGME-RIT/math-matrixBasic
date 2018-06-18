#include <iostream>
#include <conio.h>

using namespace std;

template<size_t SIZE, class T>
inline size_t array_size(T(&arr)[SIZE])
{
	return SIZE;
}

int** generateMatrix(int rows, int cols)
{
	int** temp = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols];
	}

	return temp;
}

void printMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void populateMatrix(int** matrix, int rows, int cols, int* src, int src_size)
{
	if (rows * cols != src_size)
	{
		cout << "size of matrix is not equal to the size of source array!" << endl;
		exit(-1);
	}

	int pos = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = src[pos++];
		}
	}
}

int** addMatrices(int** matA, int** matB, int rows, int cols)
{
	int** resultMat = generateMatrix(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			resultMat[i][j] = matA[i][j] + matB[i][j];
		}
	}

	return resultMat;
}

int** subMatrices(int** matA, int** matB, int rows, int cols)
{
	int** resultMat = generateMatrix(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			resultMat[i][j] = matA[i][j] - matB[i][j];
		}
	}

	return resultMat;
}

int main()
{
	int m1_src[] = { 1, 2, 3, 4 };
	int m1_rows = 2, m1_cols = 2;
	int** m1 = generateMatrix(m1_rows, m1_cols);
	
	populateMatrix(m1, m1_rows, m1_cols, m1_src, array_size(m1_src));

	int m2_src[] = { 1, 2, 3, 4 };
	int m2_rows = 2, m2_cols = 2;
	int** m2 = generateMatrix(m2_rows, m2_cols);

	populateMatrix(m2, m2_rows, m2_cols, m2_src, array_size(m2_src));

	printMatrix(addMatrices(m1, m2, m1_rows, m1_cols), m1_rows, m1_cols);

	cout << endl;

	printMatrix(subMatrices(m1, m2, m1_rows, m1_cols), m1_rows, m1_cols);

	_getch();
}