#include <iostream>

SquareMatrix pow(const SquareMatrix& A, int n);
int fib3(int n) {
	if ( n == 0 ) return 0;
	SquareMatrix W(2);
	W[0][0] = 0;
	W[0][1] = W[1][0] = W[1][1] = 1;
	return pow(W, n-1)[1][1];
}