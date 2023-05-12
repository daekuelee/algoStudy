#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int n;
const int max_n =100;
bool isPrime[max_n+1];

void eratosthenes() {
	memset(isPrime, 1, sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; ++i) 
		if (isPrime[i])
			for (int j = i * i; j <= n; j += i)
				isPrime[j] =false;
}