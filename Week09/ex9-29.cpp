#include <iostream>

using namespace std;

const int max_n = 20;
const int maxBudgetDevide100 = 200;
int n, m, price[max_n], pref[max_n];
int c[maxBudgetDevide100];

// m 은 이미 100 으로 나눠짐 price랑
int sushi3() {
	int ret = 0;
	for (int budget = 1; budget <= m; ++budget) {
		int cand = 0;
		for (int dish = 0; dish < n; ++ dish)
			if (budget >= price[dish])
				cand = max(cand,
					c[(budget - price[dish])%(maxBudgetDevide100+1)] + 
					price[dish]);
		c[budget % (maxBudgetDevide100+1)] = cand;
		ret = max(ret, cand);			
	}
	return ret;
}