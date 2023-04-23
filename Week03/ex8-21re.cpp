#include <iostream>

const int Mod = 10*1000*1000;
const int max_n = 100;
int cache[max_n+1][max_n+1];

int poly(int n, int first){
	//base case
	if (n == first) return 1;
	
	int &ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	for (int second = 1; second <= n-first; ++second){
		int add = second + first - 1;
		add *= poly(n-first, second);
		add %= Mod;
		ret += add;
		ret %= Mod;
	}
	return (ret);
}