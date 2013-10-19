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

#include "matrix.hpp"
#include "exceptions.hpp"

// For matrix-matrix addition
template <class T>
void Matrix<T>::Add(const Matrix& m) {
	if (nrows != m.nrows || ncols != m.ncols) {
		throw DimensionMismatchException();
	}

	size_t i;
	for (i = 0; i < size; i++) {
		matrix[i] = matrix[i] + m.matrix[i];
	}
}

// For per-element value addition
template <class T>
void Matrix<T>::Add(const T v) {
	size_t i;
	for (i = 0; i < size; i++) {
		matrix[i] = matrix[i] + v;
	}
}

// For matrix-matrix subtraction
template <class T>
void Matrix<T>::Sub(const Matrix& m) {
	if (nrows != m.nrows || ncols != m.ncols) {
		throw DimensionMismatchException();
	}

	size_t i;
	for (i = 0; i < size; i++) {
		matrix[i] = matrix[i] - m.matrix[i];
	}
}

// For per-element value subtraction
template <class T>
void Matrix<T>::Sub(const T v) {
	Add(-v);
}

// For matrix-matrix multiplication
template <class T>
Matrix<T> Matrix<T>::Mult(const Matrix& m) {
	size_t i, j, k;
	size_t h = nrows + 1, h2 = m.nrows + 1, w2 = m.ncols + 1;

	if (ncols != m.nrows) {
		throw DimensionMismatchException();
	}
	Matrix n = Matrix(nrows, m.ncols);

	for (j = 1; j < h; j++) {
		for (i = 1; i< w2; i++) {
			for (k = 1; k < h2; k++) {
				n(j, i) += (*this)(j, k) * m(k, i);
			}
		}
	}
	return n;
}

// for per-element value multiplication
template <class T>
void Matrix<T>::Mult(const T v) {
	size_t i;
	for (i = 0; i < size; i++) {
		matrix[i] = matrix[i] * v;
	}
}

// for per-element value division
template <class T>
void Matrix<T>::Div(const T v) {
	T r = 1 / v;
	Mult(r);
}

// 2-Norm of matrix
template <class T>
T Matrix<T>::Norm2() {
	T v = 0.0;
	size_t i;
	for (i = 0; i < size; i++) {
		v = v + matrix[i] * matrix[i];
	}
	return v;
}

