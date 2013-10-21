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
#ifndef __MATRIX_HPP_INCLUDED__
#define __MATRIX_HPP_INCLUDED__

#include <cstddef>

template <class T>
class Matrix {
private:
	T*   matrix;                    // Array holding matrix elements data
	size_t nrows;
	size_t ncols;
	bool isTranspose;
	void init(size_t, size_t);      // Common function for constructors
	void copy(const Matrix&);
public:
	// Constructors and Destructor
	Matrix(size_t);
	Matrix(size_t, size_t);
	Matrix(const Matrix&); // For matrix duplication
	~Matrix();

	// Basic methods
	size_t size;
	size_t height() const;
	size_t width()  const;
	bool   Equal(Matrix&);
	void   Foreach(T (T));

	// Calculation methods
	void   Add(const Matrix&);
	void   Add(const T);
	void   Sub(const Matrix&);
	void   Sub(const T);
	Matrix Mult(const Matrix&) const;
	void   Mult(const T);
	void   Div(const T);

	void   Transpose();
	T      Norm2();
	T      Norm2Squared();
	Matrix VectorProduct(const Matrix&);

	// Overloaded operators
	T& operator() (size_t) const;
	T& operator() (size_t, size_t) const ;
	Matrix& operator=   (const Matrix&);
};

#endif
