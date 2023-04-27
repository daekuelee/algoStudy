#include <iostream>
#include <vector>

using namespace std;

const int max_n = 1000;
int n, e[max_n], m[max_n];

int heat() {
	vector<pair<int,int> > order;
	for (int i = 0; i < n; ++i)
		order.push_back(make_pair(-e[i],i));
	sort(order.begin(), order.end());

	int ret = 0, beginEat = 0;
	for (int i = 0; i < n; ++i) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}