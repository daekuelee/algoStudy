#include <iostream>

using namespace std;
int n, triangle[max_n][max_n];

const int max_n =10000;
int C2[2][max_n];
int iterative2() {
	for (int x = 0; x < n; ++ x)
		C2[(n-1)%2][x] = triangle[n-1][x];
	for (int y = n-2; y >= 0; --y)
		for (int x=0; x < y+1; ++x)
			C2[y%2][x] = max(C2[(y+1)%2][x], 
			C2[(y+1)%2][x+1]) + triangle[y][x];
	return C2[0][0];
}