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

int main()
{
	//Matrix Chain Heuristic Experiment

	int  arr[] = { 5, 10, 3, 12, 5, 50, 6 };
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
	long int opt_val, HA_val, HB_val, HC_val, HD_val, HE_val, HEL_val, HF_val;
	//minval = optimalchain(arr, 10);
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int l = 0; l < size; l++)
		vec_arr.push_back(arr[l]);

	// Test different heuristic algorithms
	opt_val = OMCmatrix(arr, size, table);
	HA_val = Heuristic_A(vec_arr);
	HB_val = Heuristic_B(vec_arr);
	HC_val = Heuristic_C(vec_arr);
	HD_val = Heuristic_D(vec_arr);
	HE_val = Heuristic_E(vec_arr);
	HEL_val = Heuristic_E_L(vec_arr);
	HF_val = Heuristic_F(vec_arr);

	cout << "Optimal Cost: " << opt_val << endl;
	cout << "Heuristic A: " << HA_val << endl;
	cout << "Heuristic B: " << HB_val << endl;
	cout << "Heuristic C: " << HC_val << endl;
	cout << "Heuristic D: " << HD_val << endl;
	cout << "Heuristic E: " << HE_val << endl;
	cout << "Heuristic F: " << HF_val << endl;
	cout << "HE L: " << HEL_val << endl;

	system("pause");
}

// Previously the contents of main()
/*
for (int m = 0; m < 7; m++)
{
cout << (rand() % 6) + 1 << " ";
}

system("pause");

int  arr[] = { 5, 10, 3, 12, 5, 50, 6 };
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
long int opt_val, HA_val, HB_val, HC_val, HD_val, HE_val, HF_val;
//minval = optimalchain(arr, 10);
int size = sizeof(arr) / sizeof(arr[0]);

for (int l = 0; l < size; l++)
	vec_arr.push_back(arr[l]);

// Test different heuristic algorithms
opt_val = OMCmatrix(arr, size, table);
HA_val = Heuristic_A(vec_arr);
HB_val = Heuristic_B(vec_arr);
HC_val = Heuristic_C(vec_arr);
HD_val = Heuristic_D(vec_arr);
HE_val = Heuristic_E(vec_arr);
HF_val = Heuristic_F(vec_arr);

cout << "Optimal Cost: " << opt_val << endl;
cout << "Heuristic A: " << HA_val << endl;
cout << "Heuristic B: " << HB_val << endl;
cout << "Heuristic C: " << HC_val << endl;
cout << "Heuristic D: " << HD_val << endl;
cout << "Heuristic E: " << HE_val << endl;
cout << "Heuristic F: " << HF_val << endl;

system("pause");
*/