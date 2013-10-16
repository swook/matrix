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

// Include dependencies
#include <vector>

using namespace std;

template <class T>
class Matrix {
private:
	std::vector< vector<T> > matrix;
	void init(int, int);
public:
	// Constructors and Destructor
	Matrix(int);
	Matrix(int, int);
	~Matrix();

	// Basic methods
	int height();
	int width();
	bool Equal(Matrix&);
	Matrix Duplicate();

	// Calculation methods
	void Add(Matrix&);
	void Add(T);
	void Sub(Matrix&);
	void Sub(T);
	Matrix Mult(Matrix&);
	void Mult(T);
	void Div(T);
	void Foreach(T f(T));

	// Overloaded operators
	double operator() (int, int);
	void operator() (int, int, double);

	Matrix operator+ (Matrix&);
	Matrix operator+ (T);
	Matrix operator- (Matrix&);
	Matrix operator- (T);
	Matrix operator* (Matrix&);
	Matrix operator* (T);
	Matrix operator/ (T);
};

#endif
