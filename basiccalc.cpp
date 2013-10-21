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

#include <cmath>
#include "matrix.hpp"
#include "exceptions.hpp"

template <class T>
void Matrix<T>::Transpose() {
	isTranspose = !isTranspose;
}

// For matrix-matrix addition
template <class T>
void Matrix<T>::Add(const Matrix& m) {
	if (height() != m.height() || width() != m.width()) {
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
	if (height() != m.height() || width() != m.width()) {
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
	size_t h = height() + 1, h2 = m.height() + 1, w2 = m.width() + 1;

	if (width() != m.height()) {
		throw DimensionMismatchException();
	}
	Matrix n = Matrix(height(), m.width());

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
	return sqrt(Norm2Squared());
}

// 2-Norm of matrix
template <class T>
T Matrix<T>::Norm2Squared() {
	T v = 0.0;
	size_t i;
	for (i = 0; i < size; i++) {
		v = v + matrix[i] * matrix[i];
	}
	return v;
}

// 3x1 matrix cross product
template <class T>
Matrix<T> Matrix<T>::VectorProduct(const Matrix& m) {
	if (height() != 3 || m.height() != 3 || width() != 1 || m.width() != 3) {
		throw InvalidDimensionException();
	}

	Matrix n = Matrix(3, 1);
	n.matrix[0] = matrix[1] * m.matrix[2] - matrix[2] * m.matrix[1];
	n.matrix[1] = matrix[2] * m.matrix[0] - matrix[0] * m.matrix[2];
	n.matrix[2] = matrix[0] * m.matrix[1] - matrix[1] * m.matrix[0];

	return n;
}
