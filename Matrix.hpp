#ifndef MATRIXDEF
#define MATRIXDEF
#include<iostream>
#include "Vector.hpp"


class Matrix
{
private:
	double** mData; // data stored in matrix
	int m_row_num, m_col_num; // dimensions

public:
	Matrix(const Matrix& Matrix1);
	Matrix(int row_num, int col_num);
	~Matrix();
	int Get_row_num() const;
	int Get_col_num() const;
	double& operator() (int i, int j);  //used to access the element in matrix with row i and col j
	Matrix& operator=(const Matrix& Matrix1);

	// unary operator
	friend Matrix operator-(const Matrix& m);

	// output
	friend std::ostream& operator<<(std::ostream& output, const Matrix& m);

	// binary + operator
	friend Matrix operator+(const Matrix& Matrix1, const Matrix& Matrix2);  

	// binary - operator
	friend Matrix operator-(const Matrix& Matrix1, const Matrix& Matrix2);

	// Matrix * vector
	friend Vector operator*(const Matrix& A, const Vector& v);
};


// unary operator
Matrix operator-(const Matrix& m);

// binary + operator
Matrix operator+(const Matrix& Matrix1, const Matrix& Matrix2);

// binary - operator
Matrix operator-(const Matrix& Matrix1, const Matrix& Matrix2);

// Matrix * vector
Vector operator*(const Matrix& A, const Vector& v);

#endif
