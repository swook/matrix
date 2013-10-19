// Copyright 2103 Seon-Wook Park
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
	Matrix<double> m = Matrix<double>(4, 3);
	Matrix<double> n = Matrix<double>(m);

	// Width, Height test
	if (m.nrows == 4 && m.ncols == 3 && m.size == 12) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " .ncols, .nrows and .size" << endl;

	// Assignment test
	m(1, 1) = 1.0;
	if (m(1, 1) == 1.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Assignment by ()" << endl;

	Matrix<double> m2 = Matrix<double>(3, 2);
	m2(3, 1) = 2.0;

	// Duplication test
	Matrix<double> m_ = Matrix<double>(m);
	if (m_(1, 1) == 1.0) {
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
	m_(2, 2) = 3.0;
	m.Add(m_);
	if (m(1, 1) == 2.0 && m(2, 2) == 3.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Add" << endl;

	// Mat-Mat + test
	n = m + m_;
	if (n(1, 1) == 3.0 && n(2, 2) == 6.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Add with +" << endl;

	// Mat-Mat Subtraction test
	m.Sub(m_);
	if (m(1, 1) == 1.0 && m(2, 2) == 0.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Sub" << endl;

	// Mat-Mat - test
	n = m_ - m - m;
	if (n(1, 1) == -1.0 && n(2, 2) == 3.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Sub with -" << endl;

	// Mat-Mat Multiplication test
	m(2, 3) = 9.0;
	m2(1, 1) = 5.0;
	n = m.Mult(m2);
	if (n(1, 1) == 5.0 && n(2, 1) == 18) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Mult" << endl;

	// Mat-Mat * test
	n = m * m2;
	if (n(1, 1) == 5.0 && n(2, 1) == 18) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-matrix Mult with *" << endl;

	// Mat-T Addition test
	if (m(1, 1) == 1.0 && m(2, 3) == 9.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Add" << endl;

	// Mat-T + test
	n = m + 1.0;
	if (n(1, 1) == 2.0 && n(2, 3) == 10.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value +" << endl;

	// Mat-T Subtraction test
	m.Sub(-2.0);
	if (m(1, 1) == 3.0 && m(2, 3) == 11.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Sub" << endl;

	// Mat-T - test
	n = m - 5.0;
	if (n(1, 1) == -2.0 && n(2, 3) == 6.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value -" << endl;

	// Mat-T Multiplication test
	m.Mult(4.0);
	if (m(1, 1) == 12.0 && m(2, 3) == 44.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Mult" << endl;

	// Mat-T Multiplication test
	n = m * 11.0;
	if (n(1, 1) == 132.0 && n(2, 3) == 484.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value *" << endl;

	// Mat-T Division test
	m.Div(2.0);
	if (m(1, 1) == 6.0 && m(2, 3) == 22.0) {
		cout << "[PASS]";
	} else {
		cout << "[FAIL]";
	}
	cout << " Matrix-by-value Div" << endl;
}
