#include <iostream>

using namespace std;

const int max_n = 100;

int n, triangle[max_n][max_n];
int C[max_n][max_n];
int iterative() {
	//base
	for (int x= 0; x<n; ++x)
		C[n-1][x] = triangle[n-1][x];
	
	for (int y = n-2; y>= 0; --y)
		for (int x =0; x < y+1; ++x)
			C[y][x] = max(C[y+1][x], C[y+1][x+1]) + triangle[y][x];
	return C[0][0];
}