#include <iostream>

using namespace std;

const int max_n = 20;
const int maxBudget = 20000;
int n, m, price[max_n], pref[max_n];
int cache[maxBudget+1];

int sushi2() {
	int ret = 0;
	for (int budget = 1; budget <= m; ++budget) {
		cache[budget] = 0;
		for (int dish = 0; dish < n; ++dish)
			if (budget >= price[dish])
				cache[budget] = max(cache[budget],
					cache[budget - price[dish]] + pref[dish]);
		ret = max(ret, cache[budget]);
	}
	return ret;
}
