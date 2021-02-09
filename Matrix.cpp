#include <cmath>
#include <cassert>
#include<iostream>
using namespace std;
#include "Matrix.hpp"
#include "Vector.hpp"

// constructor that creates matrix of given dimension with
// double precision entries all initially set to zero

Matrix::Matrix(int rownum, int colnum)
{
	m_row_num = rownum;
	m_col_num = colnum;
	mData = new double* [m_row_num];
	for (int i = 0; i < m_row_num; i++)
	{
		mData[i] = new double[m_col_num];
	}
	for (int i = 0; i < m_row_num; i++)
	{
		for (int j = 0; j < m_col_num; j++)
		{
			mData[i][j] = 0.0;
		}
	}
}


// copy constructor - creates matrix with the same entries as Matrix1

Matrix::Matrix(const Matrix& Matrix1)
{
	m_row_num = Matrix1.m_row_num;
	m_col_num = Matrix1.m_col_num;
	mData = new double* [m_row_num];
	for (int i = 0; i < m_row_num; i++)
	{
		mData[i] = new double[m_col_num];
	}
	for (int i = 0; i < m_row_num; i++)
	{
		for (int j = 0; j < m_col_num; j++)
		{
			mData[i][j] = Matrix1.mData[i][j];
		}
	}
}


// destructor - deletes pointer

Matrix::~Matrix()
{
	for (int i = 0; i < m_row_num; i++)
	{
		delete[] mData[i];
	}
	delete[] mData;
}


// get row number
int Matrix::Get_row_num() const
{
	return m_row_num;
}


// get column number
int Matrix::Get_col_num() const
{
	return m_col_num;
}


// overloading for accessing elements of matrix using indices
double& Matrix::operator()(int i, int j)
{
	assert(i > 0);
	assert(i < m_row_num + 1);
	assert(j > 0);
	assert(j < m_col_num + 1);
	return mData[i - 1][j - 1];
}


// overloading = assignment operator
Matrix& Matrix::operator=(const Matrix& Matrix1)
{
	assert(m_row_num == Matrix1.m_row_num);
	assert(m_col_num == Matrix1.m_col_num);
	for (int i = 0; i < m_row_num; i++)
	{
		for (int j = 0; j < m_col_num; j++)
		{
			mData[i][j] = Matrix1.mData[i][j];
		}
	}
	return *this;
}


// definition of the unary operator -
Matrix operator-(const Matrix& m)
{

	//  create a matrix w with entries equal to -m

	Matrix w(m.m_row_num,m.m_col_num);

	for (int i = 0; i < m.m_row_num; i++)
	{
		for (int j = 0; j < m.m_col_num; j++)
		{
			w.mData[i][j] = -m.mData[i][j];
		}
	}

	return w;
}


/*   这是我找的另一种方法,下面一个block是vector写法改造的,不过都不对

Matrix Matrix::operator+(const Matrix& Matrix1) const
{
	assert(m_row_num == Matrix1.m_row_num);
	assert(m_col_num == Matrix1.m_col_num);
	Matrix this_matrix(m_row_num, m_col_num);
	for (int i = 0; i < m_row_num; i++)
	{
		for (int j = 0; j < m_col_num; j++)
		{
			this_matrix(i + 1, j + 1) = mData[i][j] + Matrix1.mData[i][j];
		}
	}
}

*/



Matrix operator+(const Matrix& Matrix1, const Matrix& Matrix2)
{
	int m, n;
	m = Matrix1.m_row_num;
	n = Matrix1.m_col_num;
	Matrix w(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			w.mData[i][j] = Matrix1.mData[i][j] + Matrix2.mData[i][j];
		}
	}
	return w;
}


Matrix operator-(const Matrix& Matrix1, const Matrix& Matrix2)
{
	int m, n;
	m = Matrix1.m_row_num;
	n = Matrix1.m_col_num;
	Matrix w(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			w.mData[i][j] = Matrix1.mData[i][j] - Matrix2.mData[i][j];
		}
	}
	return w;
}


Vector operator*(const Matrix& A, const Vector& v)
{
	Vector w(A.m_row_num);
	Vector m_v(A.m_col_num);
    m_v = v;
	
	for (int i = 1; i <= A.m_row_num; i++)
	{
		for (int j = 1; j <= A.m_col_num; j++)
		{
			w(i) += A.mData[i-1][j-1]*m_v(j);
		}
	}
	return w;
}



std::ostream& operator<<(std::ostream& output, const Matrix& m) {
	
	for (int i = 0; i < m.m_row_num; i++)
	{
		for (int j = 0; j < m.m_col_num; j++)
		{
			output << m.mData[i][j]<<" ";
			
		}
		output << endl;
	}
	return output;  // for multiple << operators.
}

