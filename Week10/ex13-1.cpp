#include <iostream>
#include <cmath>

using namespace std;
double f(double x);

double bisection(double lo, double hi) {
	//반복 불변식을 강제
	if (f(lo) > 0)
		swap(lo, hi);
	//반복문 불변식 f(lo) <= 0 < f(hi)
	while (fabs(hi - lo) > 2e-7) {
		double mid = (lo + hi) / 2;
		double fmid = f(mid);
		if (fmid <= 0)
			lo = mid;
		else
			hi = mid;
	}
	return (lo + hi) / 2;
}