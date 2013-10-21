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

// Retrieves double stored in index i.
// Note: The order of indexing is irrespective of whether the matrix is in a
// transpose state.
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
	if (i == 0 || j == 0 || i > width() || j > height()) {
		throw IndexOutOfBoundsException();
	}
	i--;
	j--;
	if (isTranspose) {
		return matrix[j + i*ncols];
	} else {
		return matrix[j*ncols + i];
	}
}

// << overload to allow for formatting Matrix with cout.
template <class T>
std::ostream& operator<< (std::ostream& out, Matrix<T>& m) {
	size_t i, j, h = m.height() + 1, w = m.width() + 1;
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

// = overload to assign copies of matrices to variables
template <class T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& m) {
	copy(m);
	return *this;
}

// Convenience + overload for adding matrices.
// Note: Duplicates this matrix to return answer.
template <class T>
Matrix<T> operator+ (const Matrix<T>& m1, const Matrix<T>& m2) {
	Matrix<T> n = Matrix<T>(m1);
	n.Add(m2);
	return n;
}

template <class T>
Matrix<T> operator+ (const Matrix<T>& m, const T v) {
	Matrix<T> n = Matrix<T>(m);
	n.Add(v);
	return n;
}
template <class T>
Matrix<T> operator+ (const T v, const Matrix<T>& m) {
	Matrix<T> n = Matrix<T>(m);
	n.Add(v);
	return n;
}

// Convenience - overload for subtracting matrices.
// Note: Duplicates this matrix to return answer.
template <class T>
Matrix<T> operator- (const Matrix<T>& m1, const Matrix<T>& m2) {
	Matrix<T> n = Matrix<T>(m1);
	n.Sub(m2);
	return n;
}

template <class T>
Matrix<T> operator- (const Matrix<T>& m, const T v) {
	Matrix<T> n = Matrix<T>(m);
	n.Sub(v);
	return n;
}
template <class T>
Matrix<T> operator- (const T v, const Matrix<T>& m) {
	Matrix<T> n = Matrix<T>(m);
	n.Mult(-1.0);
	n.Add(v);
	return n;
}

// * overload for multiplying matrices.
// Note: Necessarily creates new matrix to return answer by value.
template <class T>
Matrix<T> operator* (const Matrix<T>& m1, const Matrix<T>& m2) {
	return m1.Mult(m2);
}

template <class T>
Matrix<T> operator* (const Matrix<T>& m, const T v) {
	Matrix<T> n = Matrix<T>(m);
	n.Mult(v);
	return n;
}
template <class T>
Matrix<T> operator* (const T v, const Matrix<T>& m) {
	Matrix<T> n = Matrix<T>(m);
	n.Mult(v);
	return n;
}

// / overload for dividing matrix elements by provided value.
// Note: Necessarily creates new matrix to return answer by value.
template <class T>
Matrix<T> operator/ (const Matrix<T>& m, const T v) {
	Matrix<T> n = Matrix<T>(m);
	n.Div(v);
	return n;
}
