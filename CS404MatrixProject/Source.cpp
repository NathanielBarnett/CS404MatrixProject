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
void Heuristic_Experiment(string file);
void Heuristic_Experiment();

int main()
{
	
	Heuristic_Experiment("CS404SP17MatrixChainHeuristicsInput1.txt");
	Heuristic_Experiment("CS404SP17MatrixChainHeuristicsInput2.txt");
	Heuristic_Experiment("CS404SP17MatrixChainHeuristicsInput3.txt");
	Heuristic_Experiment("CS404SP17MatrixChainHeuristicsInput4.txt");
	Heuristic_Experiment("CS404SP17MatrixChainHeuristicsInput5.txt");
	Heuristic_Experiment("CS404SP17MatrixChainHeuristicsInput6.txt");
	Heuristic_Experiment("CS404SP17MatrixChainHeuristicsInput7.txt");
	Heuristic_Experiment("input.txt");
	Heuristic_Experiment("input2.txt");
	system("pause");

	//Matrix Chain Heuristic Experiment
	//Heuristic_Experiment();
}


//Matrix Chain Heuristic Experiment
void Heuristic_Experiment() {
	// Struct to hold values for each heuristic.
	srand(time(NULL));	// Setting the seed for the random generator
	int LowValue = 7, HighValue = 17, dim = 1;
	
	for (int N = 10; N < 30; N += 5)
	{
		int Op_cost = 0;
		vector<int> vec_arr;
		H_stats Heur_A, Heur_B, Heur_C, Heur_D, Heur_E_L, Heur_F;	
		for (int r = 0; r < 30; r++)
		{
			//srand(time(NULL));
			vec_arr.clear();
			for (int i = 0; i < N; i++)
			{
				
				dim = (rand() % 10) + 7;
				vec_arr.push_back(dim);
			}
			Op_cost = OMCmatrix(vec_arr);
			Heur_A.arr_of_costs[r] = (double)Heuristic_A(vec_arr) / (double)Op_cost;
			Heur_B.arr_of_costs[r] = (double)Heuristic_B(vec_arr) / (double)Op_cost;
			Heur_C.arr_of_costs[r] = (double)Heuristic_C(vec_arr) / (double)Op_cost;
			Heur_D.arr_of_costs[r] = (double)Heuristic_D(vec_arr) / (double)Op_cost;
			Heur_E_L.arr_of_costs[r] = (double)Heuristic_E_L(vec_arr) / (double)Op_cost;
			Heur_F.arr_of_costs[r] = (double)Heuristic_F(vec_arr) / (double)Op_cost;
		}
		Compute_Heuristics(Heur_A, Heur_B, Heur_C, Heur_D, Heur_E_L, Heur_F);
		Print_Heuristics(N, Heur_A, Heur_B, Heur_C, Heur_D, Heur_E_L, Heur_F);
		cout << "Completed run for N = " << N << endl;
	}
	cout << endl << "~END EXPERIMENT~" << endl;
	//system("pause");
}



void Heuristic_Experiment(string file) {
	
	ifstream fin(file);
	if (fin.fail())
	{
		cout << "file failed to open." << endl;
	}
	cout << "File: " << file << endl;

	int current_val; char comma;
	int arr[30], counter = 0;
	vector<int> vec_arr;
	while (fin.good()) {
		fin >> current_val >> comma;
		vec_arr.push_back(current_val);
		arr[counter] = current_val;
	}
	int N = vec_arr.size();
	double Op_cost = OMCmatrix(vec_arr);
	double HA, HB, HC, HD, HE, HF;
	HA = Heuristic_A(vec_arr) / Op_cost;
	HB = Heuristic_B(vec_arr) / Op_cost;
	HC = Heuristic_C(vec_arr) / Op_cost;
	HD = Heuristic_D(vec_arr) / Op_cost;
	HE = Heuristic_E(vec_arr) / Op_cost;
	HF = Heuristic_F(vec_arr) / Op_cost;

	fin.close();

	cout << "HA: " << HA << endl << "HB: " << HB << endl << "HC: "
		<< HC << endl << "HD: " << HD << endl << "HE: " << HE << endl <<
		"HF: " << HF << endl << "Optimal: " << Op_cost << endl << endl;

}