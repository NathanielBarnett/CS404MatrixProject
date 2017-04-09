/*
Name: Nathaniel B.
Student ID: 16208536
Email: nabgz8@mail.umkc.edu
Course: CS 404 with Prof. Appie
Assignment: Matrix Chain Heauristic Project
Current File: Heuristics.h -> The header file for the functions that carry out the different heauristics and their computations.
*/

#pragma once
#include <vector>
using namespace std;

/* Heuristic A:
-> Remove largest dimension first to find the largest value of the "inner" dimensions, {d0, d1,..., d(n-1)},
-> and multiply the two matrices with this shared largest dimension.Repeat until all matrices are processed.
-> If two interior dimensions are equal, then the first occurance is used.
Pre: takes a vector of the dimensions {d0, d1,..., dn}
Post: returns the cost of following heuristic A.
*/
long int Heuristic_A(vector<int> arr);

/* Heuristic B:
-> Do most expensive matrix operation first, and repeat until only final matrix remains.
-> Find i such that the product of d(i - 1) * di * d(i + 1) is the largest from i = 1... (n - 1).
-> If the product of two different di's are equal, then the first occurance is used.
Pre: takes a vector of the dimensions {d0, d1,..., dn}.
Post: returns the cost of following heuristic B.
*/
long int Heuristic_B(vector<int> arr);

/*
Heuristic C:
-> Remove smallest dimension first, find smallest value of inner dimensions, {d1,..., d(n-1)},
-> and multiply the two matrices with this shared dimension.
-> If two interior dimensions of the same size are present, then the first occurance is used.
Pre: takes a vector of the dimensions {d0,..., dn}.
Post: returns the cost of following heuristic C.
*/
long int Heuristic_C(vector<int> arr);

/*
Heuristic D:
-> Do least expensive matrix multiplication first, find i such that the product of
-> (d(i-1) * di * d(i+1)) is the smallest from i = 1... (n-1).
-> If there exists two di's such that their respective products are equivalent,
then the first occurance in the array is used.
Pre: takes a vector of the dimensions of the matrices {d0, d1,..., dn}
Post: returns an integer value for the cost of this heuristic D's multiplication tree
*/
long int Heuristic_D(vector<int> arr);