#include <iostream>

using namespace std;

const int max_n = 20;
const int maxBudget = 10e9;
int n, m, price[max_n], pref[max_n];
int cache[maxBudget+1];

int sushi(int budget) {
	int & ret = cache[budget];
	if (ret != -1) return ret;
	ret = 0;
	for (int dish = 0; dish < n; ++ dish) {
		if (budget < price[dish]) continue ;
		ret = max(ret, sushi(budget - price[dish]) + pref[dish]);
	}
	return ret;
}