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

#include <vector>
#include "matrix.h"
#include "exceptions.h"

#include "basiccalc.cpp"
#include "operators.cpp"

using namespace std;

// Constructor for square matrix of size NxN.
template <class T>
Matrix<T>::Matrix(int N) {
	init(N, N);
}

// Constructor for matrix of size hxw.
template <class T>
Matrix<T>::Matrix(int h, int w) {
	init(h, w);
}

// Destructor for Matrix
template <class T>
Matrix<T>::~Matrix() {
	int h = height(), w = width(), i, j;
	for (j = 0; j < h; j++) {
		vector<T>().swap(matrix[j]);
	}
	vector< vector<T> >().swap(matrix);
}

// Common constructor for matrix of size hxw.
template <class T>
void Matrix<T>::init(int h, int w) {
	if (h < 1 || w < 1) {
		throw InvalidDimensionException();
		return;
	}
	matrix = vector< vector<T> >(h, vector<T>(w));
}

// Retrieve matrix height
template <class T>
int Matrix<T>::height() {
	return matrix.size();
}

// Retrieve matrix width
template <class T>
int Matrix<T>::width() {
	return matrix[0].size();
}

template <class T>
bool Matrix<T>::Equal(Matrix& m) {
	int h = height(), w = width(), i, j;
	for (j = 0; j < h; j++) {
		for (i = 0; i< w; i++) {
			if (m.matrix[j][i] != matrix[j][i]) {
				return false;
			}
		}
	}
	return true;
}

// foreach takes a function and applies a calculation per element.
template <class T>
void Matrix<T>::Foreach(T f(T)) {
	int h = height(), w = width(), i, j;
	for (j = 0; j < h; j++) {
		for (i = 0; i< w; i++) {
			matrix[j][i] = f(matrix[j][i]);
		}
	}
}

template <class T>
Matrix<T> Matrix<T>::Duplicate() {
	int h = height(), w = width(), i, j;
	Matrix m = Matrix(h, w);
	for (j = 0; j < h; j++) {
		for (i = 0; i< w; i++) {
			m.matrix[j][i] = matrix[j][i];
		}
	}
	return m;
}

