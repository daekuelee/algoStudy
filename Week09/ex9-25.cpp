#include <iostream>

const int Mod = 100000;
int fib(int n) {
	if (n <= 1) return n;
	int seq[3];
	seq[0] = 0;
	seq[1] = 1;
	for (int i = 2; i <= n; ++i)
		seq[i % 3] = (seq[(i-1) % 3] + seq[(i-2) %3]) % Mod;
	return seq[n % 3];
}