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

/* Constructors for class Matrix */

#include "matrix.h"
#include "operators.cpp"

// Constructor for square matrix of size NxN.
template <class T>
Matrix<T>::Matrix(size_t N) {
	init(N, N);
}

// Constructor for matrix of size hxw.
template <class T>
Matrix<T>::Matrix(size_t h, size_t w) {
	init(h, w);
}

// Constructor for duplicating existing matrix.
template <class T>
Matrix<T>::Matrix(const Matrix& m) {
	init(m.nrows, m.ncols);
	size_t i;
	for (i = 0; i < size; i++) {
		matrix[i] = m.matrix[i];
	}
}

// Destructor declaration for future use.
template <class T>
Matrix<T>::~Matrix() {
}

// Common constructor for matrix of size hxw.
template <class T>
void Matrix<T>::init(size_t h, size_t w) {
	if (h < 1 || w < 1) {
		throw InvalidDimensionException();
		return;
	}
	nrows = h, ncols = w, size = h * w;
	matrix = new T[size * sizeof(T)];
}

// Equal compares each element of a matrix to see if a provided matrix is equal
// to this matrix.
template <class T>
bool Matrix<T>::Equal(Matrix& m) {
	// Return if dimensions mis-match
	if (m.nrows != nrows || m.ncols != ncols || m.size != size) {
		return false;
	}
	// Element-by-element == comparison
	size_t i;
	for (i = 0; i < size; i++) {
		if (m.matrix[i] != matrix[i]) {
			return false;
		}
	}
	return true;
}

// foreach takes a function and applies a calculation per element.
template <class T>
void Matrix<T>::Foreach(T f(T)) {
	size_t i;
	for (i = 0; i < size; i++) {
		matrix[i] = f(matrix[i]);
	}
}
