#include <iostream>

int n,d,p,q;

const int max_n = 50;
const int max_d = 50;
double cache[max_n+1][max_d+1];

bool connected[max_n+1][max_n+1];
int degree[max_n+1];

double search2(int here, int days) {
	if (days == d) return (here == q? 1.0 : 0.0);

	double &ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int next = 0; next < n; ++next)
		if (connected[here][next])
			ret += search2(next, days+1) / degree[here];
	return (ret);
}