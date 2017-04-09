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
// Heuristic A -> Remove largest dimension first to find the largest value of the "inner" dimensions, {d0, d1,..., d(n-1)}, 
//		and multiply the two matrices with this shared largest dimension.Repeat until all matrices are processed.
int Heuristic_A(vector<int> arr);

/* Heuristic B -> Do most expensive matrix operation first, and repeat until only final matrix remains.
			-> Find i such that the product of d(i - 1) * di * d(i + 1) is the largest from i = 1... (n - 1).
		Pre: takes a vector of the dimensions {d0, d1,..., dn}
		Post: returns the cost of following this heuristic.
*/
int Heuristic_B(vector<int> arr);