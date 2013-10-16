// Copyright 2013 Seon-Wook Park
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <vector>
#include "stdio.h"
#include "matrix.h"
#include "exceptions.h"

#include "basiccalc.cpp"

// Retrieve double stored in index (j, i).
// Indexing starts at 1.
template <class T>
double Matrix<T>::operator() (int j, int i) {
	if (i < 1 || j < 1) {
		throw IndexOutOfBoundsException();
	}
	double v = matrix[--j][--i];
	return v;
}

// Assign an index with value v.
// Indexing starts at 1.
template <class T>
void Matrix<T>::operator() (int j, int i, double v) {
	if (i < 1 || j < 1) {
		throw IndexOutOfBoundsException();
	}
	matrix[--j][--i] = v;
}

template <class T>
ostream& operator<< (ostream& out, Matrix<T>& m) {
	int h = m.height() + 1, w = m.width() + 1, i, j;
	out << "[\n";
	for (j = 1; j < h; j++) {
		for (i = 1; i< w; i++) {
			out << "\t" << m(j, i);
		}
		out << "\n";
	}
	out << "]";
	return out;
}

// Convenience + overload for adding matrices.
// Note: Duplicates this matrix to return answer.
template <class T>
Matrix<T> Matrix<T>::operator+ (Matrix& m) {
	Matrix m0 = Duplicate();
	m0.Add(m);
	return m0;
}

template <class T>
Matrix<T> Matrix<T>::operator+ (T v) {
	Matrix m0 = Duplicate();
	m0.Add(v);
	return m0;
}

// Convenience - overload for adding matrices.
// Note: Duplicates this matrix to return answer.
template <class T>
Matrix<T> Matrix<T>::operator- (Matrix& m) {
	Matrix m0 = Duplicate();
	m0.Sub(m);
	return m0;
}

template <class T>
Matrix<T> Matrix<T>::operator- (T v) {
	Matrix m0 = Duplicate();
	m0.Sub(v);
	return m0;
}

// * overload for multiplying matrices.
// Note: Necessarily creates new matrix to return answer by value.
template <class T>
Matrix<T> Matrix<T>::operator* (Matrix& m) {
	return Mult(m);
}

template <class T>
Matrix<T> Matrix<T>::operator* (T v) {
	Matrix m0 = Duplicate();
	m0.Mult(v);
	return m0;
}

template <class T>
Matrix<T> Matrix<T>::operator/ (T v) {
	Matrix m0 = Duplicate();
	m0.Div(v);
	return m0;
}
