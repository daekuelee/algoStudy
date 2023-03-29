#include <iostream>

const int max_n = 100;
int cache[max_n];
int S[max_n];
int n;
int lis(int start){
	int &ret = cache[start];
	if (ret != -1) return (ret);

	ret = 1;
	for (int next = start + 1; next < n; next++){
		if (S[start] < S[next])
			ret = std::max(ret, lis(next) + 1);
	}
	return (ret);
}