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

#include <iostream>

#include "matrix.hpp"
#include "exceptions.hpp"
#include "basiccalc.cpp"

// Retrieves double stored in index i where i = row_number * nrows + col_number
// * ncols.
template <class T>
T& Matrix<T>::operator() (size_t i) const {
	if (i == 0 || i > size) {
		throw IndexOutOfBoundsException();
	}
	i--;
	return matrix[i];
}

// Retrieve double stored in index (j, i).
// Indexing starts at 0.
template <class T>
T& Matrix<T>::operator() (size_t j, size_t i) const {
	if (i == 0 || j == 0 || i > ncols || j > nrows) {
		throw IndexOutOfBoundsException();
	}
	i--;
	j--;
	return matrix[j*nrows + i*ncols];
}

// << overload to allow for formatting Matrix with cout.
template <class T>
std::ostream& operator<< (std::ostream& out, Matrix<T>& m) {
	size_t i, j, h = m.nrows + 1, w = m.ncols + 1;
	out << "[\n";
	for (j = 1; j < h; j++) {
		for (i = 1; i < w; i++) {
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
Matrix<T> Matrix<T>::operator+ (const Matrix& m) {
	Matrix m0 = *(new Matrix(*this));
	m0.Add(m);
	return m0;
}

template <class T>
Matrix<T> Matrix<T>::operator+ (const T v) {
	Matrix m0 = Matrix(*this);
	m0.Add(v);
	return m0;
}

// Convenience - overload for subtracting matrices.
// Note: Duplicates this matrix to return answer.
template <class T>
Matrix<T> Matrix<T>::operator- (const Matrix& m) {
	Matrix m0 = Matrix(*this);
	m0.Sub(m);
	return m0;
}

template <class T>
Matrix<T> Matrix<T>::operator- (const T v) {
	Matrix m0 = Matrix(*this);
	m0.Sub(v);
	return m0;
}

// * overload for multiplying matrices.
// Note: Necessarily creates new matrix to return answer by value.
template <class T>
Matrix<T> Matrix<T>::operator* (const Matrix& m) {
	return Mult(m);
}

template <class T>
Matrix<T> Matrix<T>::operator* (const T v) {
	Matrix m0 = Matrix(*this);
	m0.Mult(v);
	return m0;
}

// / overload for dividing matrix elements by provided value.
// Note: Necessarily creates new matrix to return answer by value.
template <class T>
Matrix<T> Matrix<T>::operator/ (const T v) {
	Matrix m0 = Matrix(*this);
	m0.Div(v);
	return m0;
}
