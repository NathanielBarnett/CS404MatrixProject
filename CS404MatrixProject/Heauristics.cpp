/*
Name: Nathaniel B.
Student ID: 16208536
Email: nabgz8@mail.umkc.edu
Course: CS 404 with Prof. Appie
Assignment: Matrix Chain Heauristic Project
Current File: Heauristics.cpp -> The implementation of the various heuristics.
*/


#include "Heuristics.h"


/*
Heuristic A: Remove largest dimension first to find the largest value of the "inner" dimensions, {d0, d1,..., d(n-1)},
and multiply the two matrices with this shared largest dimension. Repeat until all matrices are processed.
*/
int Heuristic_A(vector<int> arr) {

	int max_d, idx_d;
	int accrued_cost = 0;
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

/*
Heuristic B: Do most expensive matrix operation first, and repeat until only final matrix remains.
			-> Find i such that the product of d(i - 1) * di * d(i + 1) is the largest from i = 1... (n - 1).
*/
int Heuristic_B(vector<int> arr) {

	int max_d, idx_d;
	int accrued_cost = 0;
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
		accrued_cost += arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1];

		// Remove the computed dimension.
		arr.erase(arr.begin() + idx_d);
	}
	// Return cost
	return accrued_cost;
}