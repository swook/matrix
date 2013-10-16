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
#include "matrix.h"
#include "exceptions.h"

#ifndef __BASICCALC_CPP_INCLUDED__
#define __BASICCALC_CPP_INCLUDED__

template <class T>
void Matrix<T>::Add(Matrix& m) {
	int h = height(), w = width(), i, j;

	if (h != m.height() || w != m.width()) {
		throw DimensionMismatchException();
	}

	for (j = 0; j < h; j++) {
		for (i = 0; i< w; i++) {
			matrix[j][i] = matrix[j][i] + m.matrix[j][i];
		}
	}
}

template <class T>
void Matrix<T>::Add(T v) {
	int h = height(), w = width(), i, j;

	for (j = 0; j < h; j++) {
		for (i = 0; i< w; i++) {
			matrix[j][i] = matrix[j][i] + v;
		}
	}
}

template <class T>
void Matrix<T>::Sub(Matrix& m) {
	int h = height(), w = width(), i, j;

	if (h != m.height() || w != m.width()) {
		throw DimensionMismatchException();
	}

	for (j = 0; j < h; j++) {
		for (i = 0; i< w; i++) {
			matrix[j][i] = matrix[j][i] - m.matrix[j][i];
		}
	}
}

template <class T>
void Matrix<T>::Sub(T v) {
	Add(-v);
}

template <class T>
Matrix<T> Matrix<T>::Mult(Matrix& m) {
	int h = height(), w = width(), i, j, k;
	int h2 = m.height(), w2 = m.width();

	if (w != h2) {
		throw DimensionMismatchException();
	}
	Matrix n = Matrix(h, w2);

	for (j = 0; j < h; j++) {
		for (i = 0; i< w2; i++) {
			for (k = 0; k < h2; k++) {
				n.matrix[j][i] += matrix[j][k] * m.matrix[k][i];
			}
		}
	}
	return n;
}

template <class T>
void Matrix<T>::Mult(T v) {
	int h = height(), w = width(), i, j;

	for (j = 0; j < h; j++) {
		for (i = 0; i< w; i++) {
			matrix[j][i] = matrix[j][i] * v;
		}
	}
}

template <class T>
void Matrix<T>::Div(T v) {
	v = 1 / v;
	Mult(v);
}

#endif
