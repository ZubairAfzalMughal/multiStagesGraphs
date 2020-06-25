// multi_Stages_Graphes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<List>
using namespace std;
int main()
{
	// Multi Stages Graphs
	cout << "Multi Stages Graphs \n";
	// First Make A Graphs using Matrix
	//initiallization of Graphs
	int graphs[9][9] = {
		//   0,1,2,3,4,5,6,7,8
			{0,0,0,0,0,0,0,0,0}, //0
			{0,0,2,1,3,0,0,0,0}, //1
			{0,0,0,0,0,2,3,0,0}, //2
			{0,0,0,0,0,6,7,0,0}, //3
			{0,0,0,0,0,6,8,9,0}, //4
			{0,0,0,0,0,0,0,0,6}, //5
			{0,0,0,0,0,0,0,0,7}, //6
			{0,0,0,0,0,0,0,0,5}, //7
			{0,0,0,0,0,0,0,0,0}  //8
	}; // it has total 8 Nodes / Vertices
	//displaying the graphs
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << graphs[i][j] << "\t";
		}
		cout << endl;
	}
	int n = 8;
	int stages = 4;
	int min;
	//cost array
	int cost[9]; int d[9]; int path[5];
	cost[n] = 0;
	// take the 2nd last index

	for (int i = n - 1; i >= 1; i--) {

		min = INT_MAX; // will contains the max value of interger
		for (int j = i + 1; j <= n; j++) {
			//using Formula
			if (graphs[i][j] != 0 && (graphs[i][j] + cost[j]) < min) {
				min = graphs[i][j] + cost[j];
				d[i] = j;
			}
		}
		cost[i] = min;
	}
	// Finding the Optimal Solution '
	path[0] = 0;
	path[1] = 1; // first vertices / node
	path[stages] = n; // last vertice / node

	for (int i = 2; i < stages; i++) {
		path[i] = d[path[i - 1]];
	}

	// Display the Opitmal Solution
	cout << "\n\n\nOptimal Solution\n";
	for (int i : path) {
		cout << i << "\t";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
