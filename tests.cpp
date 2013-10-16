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

/* Test file for matrix library */

#include <iostream>
#include "matrix.cpp"

using namespace std;

int main() {
	// Creation test
	Matrix<double> m = Matrix<double>(10);
	Matrix<double> n = m.Duplicate();

	// Width, Height test
	if (m.width() == 10 && m.height() == 10) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " .width() and .height()" << endl;

	// Assignment test
	m(1, 1, 1337);
	if (m(1, 1) == 1337) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Assignment by ()" << endl;

	Matrix<double> m2 = Matrix<double>(10);
	m2(10, 10, 10);

	// Duplication test
	Matrix<double> m_ = m.Duplicate();
	if (m_(1, 1) == 1337) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Duplicate" << endl;

	if (m.Equal(m_)) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Equal" << endl;

	// Mat-Mat Addition test
	m.Add(m2);
	if (m(10, 10) == 10) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Add" << endl;

	// Mat-Mat + test
	n = m + m2;
	if (n(1, 1) == 1337 && n(10, 10) == 20) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Add with +" << endl;

	// Mat-Mat Subtraction test
	m.Sub(m2);
	if (m(10, 10) == 0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Sub" << endl;

	// Mat-Mat - test
	n = m - m2;
	if (n(1, 1) == 1337 && n(10, 10) == -10) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Sub with -" << endl;

	// Mat-Mat Multiplication test
	m(10, 10, 10);
	m2(1, 1, 1);
	n = m.Mult(m2);
	if (n(1, 1) == 1337 && n(10, 10) == 100) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Mult" << endl;

	// Mat-Mat * test
	n = m * m2;
	if (n(1, 1) == 1337 && n(10, 10) == 100) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Mult with *" << endl;

	// Mat-T Addition test
	m.Add(1.0);
	if (m(1,1) == 1338 && m(10,10) == 11) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Add" << endl;

	// Mat-T + test
	n = m + 1.0;
	if (m(1,1) == 1338 && m(10,10) == 11) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Add" << endl;

	// Mat-T Subtraction test
	m.Sub(1.0);
	if (m(1,1) == 1337 && m(10,10) == 10) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Sub" << endl;

	// Mat-T - test
	n = m - 1.0;
	if (m(1,1) == 1337 && m(10,10) == 10) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value -" << endl;

	// Mat-T Multiplication test
	m.Mult(4.0);
	if (m(1,1) == 5348 && m(10,10) == 40) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Mult" << endl;

	// Mat-T Multiplication test
	n = m * 4.0;
	if (m(1,1) == 5348 && m(10,10) == 40) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Mult" << endl;

	// Mat-T Division test
	m.Div(2.0);
	if (m(1,1) == 2674 && m(10,10) == 20) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Div" << endl;
}
