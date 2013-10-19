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

/* Matrix class for basic matrix operations */

// Prevent multiple imports
#ifndef __MATRIX_H_INCLUDED__
#define __MATRIX_H_INCLUDED__

template <class T>
class Matrix {
private:
	T* matrix;			// Array holding matrix elements data
	void init(size_t, size_t);	// Common function for constructors
public:
	// Constructors and Destructor
	Matrix(size_t);
	Matrix(size_t, size_t);
	Matrix(const Matrix&);		// For matrix duplication
	~Matrix();

	// Basic methods
	size_t nrows;
	size_t ncols;
	size_t size;
	bool Equal(Matrix&);
	void Foreach(T (T));

	// Calculation methods
	void Add(Matrix&);
	void Add(T);
	void Sub(Matrix&);
	void Sub(T);
	Matrix Mult(Matrix&);
	void Mult(T);
	void Div(T);

	// Overloaded operators
	T& operator() (size_t);
	T& operator() (size_t, size_t);

	Matrix operator+ (Matrix&);
	Matrix operator+ (T);
	Matrix operator- (Matrix&);
	Matrix operator- (T);
	Matrix operator* (Matrix&);
	Matrix operator* (T);
	Matrix operator/ (T);
};

#endif
