/*
Name: Nathaniel B.
Student ID: 16208536
Email: nabgz8@mail.umkc.edu
Course: CS 404 with Prof. Appie
Assignment: Matrix Chain Heauristic Project
Current File: Source.cpp -> Source file for Heuristic program
*/

#include <iostream>
#include <cstdlib>
#include <random>
#include "Heuristics.h"

using namespace std;

long int OMCmatrix(int d_arr[], int n, long int cost_arr[]);



int main()
{
	
	int  arr[] = {5, 10, 3, 12, 5, 50, 6};
	long int table[900];
	int i = 1, j = 0;
	
	vector<int> vec_arr;
	

	while (j < 900)
	{
		table[j] = -1;
		j++;
	}
	//so, im trying this out....
	i = 1;
	j = 30;
	long int opt_val, HA_val, HB_val, HC_val, HD_val, HF_val;
	//minval = optimalchain(arr, 10);
	int size = sizeof(arr)/ sizeof(arr[0]);
	
	for (int l = 0; l < size; l++)
		vec_arr.push_back(arr[l]);

	// Test different heuristic algorithms
	opt_val = OMCmatrix(arr, size, table);
	HA_val = Heuristic_A(vec_arr);
	HB_val = Heuristic_B(vec_arr);
	HC_val = Heuristic_C(vec_arr);
	HD_val = Heuristic_D(vec_arr);
	HF_val = Heuristic_F(vec_arr);

	cout << "Optimal Cost: " << opt_val << endl;
	cout << "Heuristic A: " << HA_val << endl;
	cout << "Heuristic B: " << HB_val << endl;
	cout << "Heuristic C: " << HC_val << endl;
	cout << "Heuristic D: " << HD_val << endl;
	cout << "Heuristic F: " << HF_val << endl;

	system("pause");
}

// REFERENCE URL's: http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Dynamic/chainMatrixMult.htm	For comprehension of the algorithm
// -> http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/						For implementation reference of algorithm
/*
pre: pass in an array
post: returns the optimal minimal cost for multiplying the matrix chain
*/
long int OMCmatrix(int d_arr[], int n, long int cost_arr[]) {
	
	int i, j, k, L, q;

	/* m[i,j] = Minimum number of scalar multiplications needed
	to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying one matrix.
	for (i = 1; i<n ; i++)
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

