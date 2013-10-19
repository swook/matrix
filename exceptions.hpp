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

/* Custom exceptions */

#include <exception>

using namespace std;

// Prevent multiple imports
#ifndef __EXCEPTIONS_H_INCLUDED__
#define __EXCEPTIONS_H_INCLUDED__


// Exception for invalid dimensions provided on Matrix construction.
class InvalidDimensionException : public exception {
	virtual const char* what() const throw() {
		return "Invalid matrix dimensions provided.";
	}
};

// Exception for invalid indexing of Matrix.
class IndexOutOfBoundsException : public exception {
	virtual const char* what() const throw() {
		return "Index out of bounds.";
	}
};

// Exception for mismatching input Matrix dimensions
class DimensionMismatchException : public exception {
	virtual const char* what() const throw() {
		return "Dimension mismatch.";
	}
};

#endif
