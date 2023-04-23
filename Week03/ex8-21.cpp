#include <iostream>

const int max_n = 100;
int cache[max_n+1][max_n+1];
int poly(int n, int first){
	//base case
	if (n <= 0) return (0);
	if (n == 1) return (1);

	int &ret = cache[n][first];
	if (ret != -1) return (ret);
	ret = 0;
	for (int second = 1; second <= n - first; second++){
		ret = ret + (second + first - 1) * poly(n-first, second);
	}
	return (ret);
}