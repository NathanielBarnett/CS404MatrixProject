/*
Name: Nathaniel B.
Student ID: 16208536
Email: nabgz8@mail.umkc.edu
Course: CS 404 with Prof. Appie
Assignment: Matrix Chain Heauristic Project
Current File: Heauristics.cpp -> The implementation of the various heuristics.
*/

#include "Heuristics.h"

// Wrapper function for OMCmatrix()
long int Optimal_Cost(int arr[], int N) {
	long int Table[900];
	for (int i = 0; i < 900; i++)
	{
		Table[i] = -1;
	}
	return OMCmatrix(arr, N, Table);
}



// REFERENCE URL's: http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Dynamic/chainMatrixMult.htm	For comprehension of the algorithm
// -> http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/						For implementation reference of algorithm
/*
pre: pass in an array, the size n of the array, and an array to store the computed cost of different parenthizations.
post: returns the optimal minimal cost for multiplying the matrix chain.
*/
long int OMCmatrix(int d_arr[], int n, long int cost_arr[]) {

	int i, j, k, L, q;

	/* m[i,j] = Minimum number of scalar multiplications needed
	to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying one matrix.
	for (i = 1; i<n; i++)
		cost_arr[i * i] = 0;

	// L is chain length.
	for (L = 2; L<n; L++)
	{
		for (i = 1; i<n - L + 1; i++)
		{
			j = i + L - 1;
			cost_arr[i * j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = cost_arr[i * k] + cost_arr[(k + 1) * j] + d_arr[i - 1] * d_arr[k] * d_arr[j];
				if (q < cost_arr[i * j])
					cost_arr[i * j] = q;
			}
		}
	}

	return cost_arr[1 * (n - 1)];
}


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
		if ((accrued_cost + (arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1])) < numeric_limits<long int>::max())
			accrued_cost += arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1];
		else {
			cout << "INTEGER OVERFLOW: Heuristic A." << endl;
		}
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
	long int accrued_cost = 0, max_cost;
	while (arr.size() > 2) {	// loop until only 2 dimensions, one matrix, remain.
		max_cost = -1;
		idx_d = 1;
		for (int j = 1; j < arr.size() - 1; j++) {	// to check for most expensive matrix multiplication of remaining dimensions.
			if ((arr[j - 1] * arr[j] * arr[j + 1]) > max_cost) {
				max_cost = (arr[j - 1] * arr[j] * arr[j + 1]);
				idx_d = j;
			}
		}
		// Calculate cost to multiply out the most expensive matrix computation.
		if ((accrued_cost + max_cost) < numeric_limits<long int>::max())
			accrued_cost += max_cost;
		else
			cout << "INTEGER OVERFLOW: Heuristic B." << endl;

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
		if ((accrued_cost + arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1]) < numeric_limits<long int>::max())
			accrued_cost += arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1];
		else
			cout << "INTEGER OVERFLOW: Heuristic C." << endl;

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
	long int accrued_cost = 0, min_cost;
	while (arr.size() > 2) {	// loop until only 2 dimensions, one matrix, remain.
		min_cost = INT_MAX;
		idx_d = 1;
		for (int j = 1; j < arr.size() - 1; j++) {	// to check for the least expensive interior multiplication.
			if ((arr[j - 1] * arr[j] * arr[j + 1]) < min_cost) {
				min_cost = (arr[j - 1] * arr[j] * arr[j + 1]);
				idx_d = j;
			}
		}
		// Calculate cost of multiplying the least expensive interior multiplication.
		if ((accrued_cost + min_cost) < numeric_limits<long int>::max())
			accrued_cost += min_cost;
		else
			cout << "INTEGER OVERFLOW: Heuristic D." << endl;
		// Remove the computed dimension.
		arr.erase(arr.begin() + idx_d);
	}
	// Return cost
	return accrued_cost;
}


/*
Heuristic E:
-> Random execution tree: find a random i, and carry out the multiplication of
-> d(i - 1) * di * d(i + 1). repeat until all matrices are processed.
Pre: takes a vector of dimensions {d0,..., dn}
Post: returns a long int value for the cost of carrying out a random execution tree.
*/
long int Heuristic_E(vector<int> arr) {
	int idx_d;
	long int accrued_cost = 0;
	
	
	while (arr.size() > 2) {
		//srand(time(NULL));	// Set seed for random number generator.

		// get random number, mod by (n - 1), then increment by 1 to result with possible values between {1,..., (n - 1)}
		idx_d = (rand() % (arr.size() - 2) + 1);
		
		if (accrued_cost + (arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1]) < LONG_MAX)
			accrued_cost += arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1];
		else
			cout << "INTEGER OVERFLOW: Heuristic E." << endl;

		// Remove the computed dimension
		arr.erase(arr.begin() + idx_d);
	}
	// Return cost
	return accrued_cost;
}

/*
Heuristic E: taking the min of 2n number of random trees generated.
Pre: takes a vector of dimensions {d0,..., dn}
Post: returns the min computational cost of 2n number of random execution trees.
*/
long int Heuristic_E_L(vector<int> arr) {
	long int min = LONG_MAX, current_val = LONG_MAX;
	for (int i = 0; i < 2 * (arr.size()); i++)
	{
		current_val = Heuristic_E(arr);
		
		// check if lower than currant min.
		if (current_val < min)
			min = current_val;
	}
	return min;
}


/*
Heuristic F:
-> Ignorant approach: B1 X B2, then multiply the result with B3, and so on.
Pre: takes a vector of the dimensions of matrices {d0,..., dn}
Post: returns the long integer cost of following heuristic F.
*/
long int Heuristic_F(vector<int> arr) {
	int idx_d;
	long int accrued_cost = 0, current_cost = 0;
	while (arr.size() > 2) {	// loop until only 2 dimensions, one matrix, remain.
		idx_d = 1;
		current_cost = arr[idx_d - 1] * arr[idx_d] * arr[idx_d + 1];
		// Calculate cost of multiplying the least expensive interior multiplication.
		if ((accrued_cost + current_cost) < numeric_limits<long int>::max())
			accrued_cost += current_cost;
		else
			cout << "INTEGER OVERFLOW: Heuristic D." << endl;

		// Remove the computed dimension.
		arr.erase(arr.begin() + idx_d);

	}
	// Return cost
	return accrued_cost;
}


void Compute_Heuristics(H_stats& HA, H_stats& HB, H_stats& HC,
	H_stats& HD, H_stats& HE, H_stats& HF) {
	for (int i = 0; i < 30; i++) {
		// A
		if (HA.arr_of_costs[i] < HA.min)
			HA.min = HA.arr_of_costs[i];
		if (HA.arr_of_costs[i] > HA.max)
			HA.max = HA.arr_of_costs[i];
		HA.ave += HA.arr_of_costs[i];
		// B
		if (HB.arr_of_costs[i] < HB.min)
			HB.min = HB.arr_of_costs[i];
		if (HB.arr_of_costs[i] > HB.max)
			HB.max = HB.arr_of_costs[i];
		HB.ave += HB.arr_of_costs[i];
		// C
		if (HC.arr_of_costs[i] < HC.min)
			HC.min = HC.arr_of_costs[i];
		if (HC.arr_of_costs[i] > HC.max)
			HC.max = HC.arr_of_costs[i];
		HC.ave += HC.arr_of_costs[i];
		// D
		if (HD.arr_of_costs[i] < HD.min)
			HD.min = HD.arr_of_costs[i];
		if (HD.arr_of_costs[i] > HD.max)
			HD.max = HD.arr_of_costs[i];
		HD.ave += HD.arr_of_costs[i];
		// E
		if (HE.arr_of_costs[i] < HE.min)
			HE.min = HE.arr_of_costs[i];
		if (HE.arr_of_costs[i] > HE.max)
			HE.max = HE.arr_of_costs[i];
		HE.ave += HE.arr_of_costs[i];
		// F
		if (HF.arr_of_costs[i] < HF.min)
			HF.min = HF.arr_of_costs[i];
		if (HF.arr_of_costs[i] > HF.max)
			HF.max = HF.arr_of_costs[i];
		HF.ave += HF.arr_of_costs[i];
	}
	// now divide by 30 to get the actual average value for each heuristic.
	HA.ave = HA.ave / 30;
	HB.ave = HB.ave / 30;
	HC.ave = HC.ave / 30;
	HD.ave = HD.ave / 30;
	HE.ave = HE.ave / 30;
	HF.ave = HF.ave / 30;

}


// Print the stats for the heuristics
void Print_Heuristics(int N, H_stats& HA, H_stats& HB, H_stats& HC,
	H_stats& HD, H_stats& HE, H_stats& HF) {

	ofstream out;
	out.open("matrix_output.txt", ios::app);
	if (!out.good())
	{
		cout << "~OUTPUT FILE COULD NOT BE OPENED~" << endl;
	}

	// A
	out << "For N = " << N << ":" << endl << "Heuristic A:" << "MIN = " << HA.min;
	out << " MAX = " << HA.max << " AVE = " << HA.ave << endl;
	
	// B
	out << "For N = " << N << ":" << endl << "Heuristic B:" << "MIN = " << HB.min;
	out << " MAX = " << HB.max << " AVE = " << HB.ave << endl;

	// C
	out << "For N = " << N << ":" << endl << "Heuristic C:" << "MIN = " << HC.min;
	out << " MAX = " << HC.max << " AVE = " << HC.ave << endl;

	// D
	out << "For N = " << N << ":" << endl << "Heuristic D:" << "MIN = " << HD.min;
	out << " MAX = " << HD.max << " AVE = " << HD.ave << endl;

	// E
	out << "For N = " << N << ":" << endl << "Heuristic E:" << "MIN = " << HE.min;
	out << " MAX = " << HE.max << " AVE = " << HE.ave << endl;

	// F
	out << "For N = " << N << ":" << endl << "Heuristic F:" << "MIN = " << HF.min;
	out << " MAX = " << HF.max << " AVE = " << HF.ave << endl << endl;
}