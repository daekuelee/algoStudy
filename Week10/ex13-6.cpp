#include <iostream>

using namespace std;

//우리가 최대 치를 찾고 싶어하는 함수
double f(double x);
//lo,hi구간에서 f(x)가 최대치를 갖는 x반환
double ternary(double lo, double hi) {
	for (int it = 0; it < 100; ++it){
		double a = (2*lo + hi) / 3.0;
		double b = (lo + 2*hi) / 3.0;
		if (f(a) > f(b))
			hi = b;
		else
			lo = a;
	}
	return (lo + hi) / 2.0;
}