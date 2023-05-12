#include <iostream>
using namespace std;
int n, k;
const int max_n = 5000;
int l[max_n], m[max_n], g[max_n];
//결정 문제 dist 지점 까지 가면서 k개 이상의 표지판을 만날 수 있는가?
bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; ++i)
		// i번쨰 도시 표지판을 하나 이상 보게 되는가?
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] +1;
	return ret >= k;
}

int optimize() {
	//반복 불변식 !decision(hi) && decision(hi)
	int lo = -1, hi = 8030001;
	while (lo+1 < hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}