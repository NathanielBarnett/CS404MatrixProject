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

void Heuristic_Experiment();

int main()
{
	//Matrix Chain Heuristic Experiment
	Heuristic_Experiment();
}


//Matrix Chain Heuristic Experiment
void Heuristic_Experiment() {
	// Struct to hold values for each heuristic.

	H_stats Heur_A, Heur_B, Heur_C, Heur_D, Heur_E_L, Heur_F;
	long int Op_cost = 0;
	int LowValue = 7, HighValue = 17, dim = 1;
	vector<int> vec_arr;
	int arr[30];
	for (int N = 10; N < 30; N += 5)
	{
		for (int r = 0; r < 30; r++)
		{
			srand(time(NULL));
			vec_arr.clear();
			for (int i = 0; i < N; i++)
			{
				
				dim = (rand() % 10) + 7;
				arr[i] = dim;
				vec_arr.push_back(dim);
			}
			Op_cost = Optimal_Cost(arr, N);
			Heur_A.arr_of_costs[r] = double(Heuristic_A(vec_arr)) / double(Op_cost);
			Heur_B.arr_of_costs[r] = double(Heuristic_B(vec_arr)) / double(Op_cost);
			Heur_C.arr_of_costs[r] = double(Heuristic_C(vec_arr)) / double(Op_cost);
			Heur_D.arr_of_costs[r] = double(Heuristic_D(vec_arr)) / double(Op_cost);
			Heur_E_L.arr_of_costs[r] = double(Heuristic_E_L(vec_arr)) / double(Op_cost);
			Heur_F.arr_of_costs[r] = double(Heuristic_F(vec_arr)) / double(Op_cost);
		}
		Compute_Heuristics(Heur_A, Heur_B, Heur_C, Heur_D, Heur_E_L, Heur_F);
		Print_Heuristics(N, Heur_A, Heur_B, Heur_C, Heur_D, Heur_E_L, Heur_F);
		cout << "Completed run for N = " << N << endl;
	}
	cout << endl << "~END EXPERIMENT~" << endl;
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