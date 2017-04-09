/*
Name: Nathaniel B.
Student ID: 16208536
Email: nabgz8@mail.umkc.edu
Course: CS 404 with Prof. Appie
Assignment: Matrix Chain Heauristic Project
Current File: Heauristics.cpp -> The implementation of the various heuristics.
*/

#include "Heuristics.h"


/* Heuristic A: 
-> Remove largest dimension first to find the largest value of the "inner" dimensions, {d0, d1,..., d(n-1)},
-> and multiply the two matrices with this shared largest dimension.Repeat until all matrices are processed.
-> If two interior dimensions are equal, then the first occurance is used.
Pre: takes a vector of the dimensions {d0, d1,..., dn}
Post: returns the cost of following heuristic A.
*/
long int Heuristic_A(vector<int> arr) {

	int idx_d;
	long int accrued_cost = 0, max_d;
	while (arr.size() > 2) {	// loop until only 2 dimensions, one matrix, remain.
		max_d = -1;
		idx_d = 1;
		for (int j = 1; j < arr.size() - 1; j++) {	// to check for largest dimension, excluding the outermost dimensions.
			if (arr[j] > max_d) {
				max_d = arr[j];
				idx_d = j;
			}
		}
		// Calculate cost to multiply out the largest interior dimension.
		accrued_cost += arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1];

		// Remove the largest dimenson.
		arr.erase(arr.begin() + idx_d);
	}
	// Return cost
	return accrued_cost;
}

/* Heuristic B:
-> Do most expensive matrix operation first, and repeat until only final matrix remains.
-> Find i such that the product of d(i - 1) * di * d(i + 1) is the largest from i = 1... (n - 1).
-> If the product of two different di's are equal, then the first occurance is used.
Pre: takes a vector of the dimensions {d0, d1,..., dn}.
Post: returns the cost of following heuristic B.
*/
long int Heuristic_B(vector<int> arr) {

	int idx_d;
	long int accrued_cost = 0, max_d;
	while (arr.size() > 2) {	// loop until only 2 dimensions, one matrix, remain.
		max_d = -1;
		idx_d = 1;
		for (int j = 1; j < arr.size() - 1; j++) {	// to check for most expensive matrix multiplication of remaining dimensions.
			if ((arr[j - 1] * arr[j] * arr[j + 1]) > max_d) {
				max_d = (arr[j - 1] * arr[j] * arr[j + 1]);
				idx_d = j;
			}
		}
		// Calculate cost to multiply out the most expensive matrix computation.
		accrued_cost += max_d;

		// Remove the computed dimension.
		arr.erase(arr.begin() + idx_d);
	}
	// Return cost
	return accrued_cost;
}


/*
Heuristic C:
-> Remove smallest dimension first, find smallest value of inner dimensions, {d1,..., d(n-1)},
-> and multiply the two matrices with this shared dimension. 
-> If two interior dimensions of the same size are present, then the first occurance is used.
Pre: takes a vector of the dimensions {d0,..., dn}.
Post: returns the cost of following heuristic C.
*/
long int Heuristic_C(vector<int> arr) {

	int idx_d;
	long int accrued_cost = 0, min_d;
	while (arr.size() > 2) {	// loop until only 2 dimensions, one matrix, remain.
		min_d = INT_MAX;
		idx_d = 1;
		for (int j = 1; j < arr.size() - 1; j++) {	// to check for smallest interior dimension.
			if (arr[j] < min_d) {
				min_d = arr[j];
				idx_d = j;
			}
		}
		// Calculate cost of multiplying the smallest dimension out.
		accrued_cost += arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1];

		// Remove the computed dimension.
		arr.erase(arr.begin() + idx_d);
	}
	// Return cost
	return accrued_cost;
}


/*
Heuristic D:
-> Do least expensive matrix multiplication first, find i such that the product of
-> (d(i-1) * di * d(i+1)) is the smallest from i = 1... (n-1).
-> If there exists two di's such that their respective products are equivalent, 
	then the first occurance in the array is used.
	Pre: takes a vector of the dimensions of the matrices {d0, d1,..., dn}
	Post: returns an integer value for the cost of this heuristic D's multiplication tree
*/
long int Heuristic_D(vector<int> arr) {

	int idx_d;
	long int accrued_cost = 0, min_d;
	while (arr.size() > 2) {	// loop until only 2 dimensions, one matrix, remain.
		min_d = INT_MAX;
		idx_d = 1;
		for (int j = 1; j < arr.size() - 1; j++) {	// to check for the least expensive interior multiplication.
			if ((arr[j - 1] * arr[j] * arr[j + 1]) < min_d) {
				min_d = (arr[j - 1] * arr[j] * arr[j + 1]);
				idx_d = j;
			}
		}
		// Calculate cost of multiplying the least expensive interior multiplication.
		accrued_cost += min_d;

		// Remove the computed dimension.
		arr.erase(arr.begin() + idx_d);
	}
	// Return cost
	return accrued_cost;
}