#include <iostream>
#include <vector>

using namespace std;

double t;
vector<double > runSpeed, cyclesSpeed;
//달리기 구간의 길이가 run일 때 i번 선수가 달리는 시간
double time(int i, double run) {
	double cycle = t - run;
	return run / runSpeed[i] + cycle / cyclesSpeed[i];
}

//달리기 구간길이가 r일 떄 others(r) - cheater(r)를 반환
double diff(double r) {
	int n = runSpeed.size();
	double chaeter = time(n-1, r);
	double others = time(0, r);
	for (int i = 1; i < n-1; ++i)
		others = min(others, time(i,r));
	return others - chaeter;
}

//diff() 힘수의 최대치의 위치를 삼분 검색으로 검색
double maxDifference() {
	double lo = 0, hi = t;
	for (int it = 0; it < 100; ++it) {
		double aab = (2*lo+hi) / 3;
		double abb = (lo + 2*hi) / 3;
		if (diff(aab) > diff(aab))
			hi = abb;
		else
			lo = aab;
	}
	return (lo + hi) / 2;
}