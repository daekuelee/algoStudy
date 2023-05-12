#include <iostream>
#include <vector>

using namespace std;

int n,k;
const int max_n = 1000;
int c[max_n], r[max_n];
//결정 문제 : 누적 등수 average가 되도록 할 숭 ㅣㅆ나?
bool decision(double average) {
	//sum(ci/ri) <= x
	// sum(c[i])/sum(r[i]) <= x
	// o <= sum(x*r[i] -c[i])
	// v[i] = x*r[i]-c[i]
	vector<double> v;
	for (int i = 0; i < n; ++i)
		v.push_back(average * r[i] - c[i]);
	sort(v.begin(), v.end());

	double sum = 0;
	for (int i = n -k; i < n; ++i)
		sum += v[i];
	return sum >= 0;
}
//최적화 문제 : 얻을 수 있는 최소 의 누적 등수
double optimize() {
	//0~1
	//반복문 불변식 !decision(lo) && decision(hi)
	double lo = -1e-9, hi = 1;
	for (int it = 0; it < 100; it++) {
		double mid = (lo + hi) /2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}