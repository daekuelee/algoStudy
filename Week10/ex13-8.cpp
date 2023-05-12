#include <iostream>
#include <vector>

using namespace std;
struct point {
	double y,x;

};
//입력에 주어진 볼록 다각형
vector<point> hull1, hull2;
//위 껍질에 속하는 선분들과 아래 껍질에 속하는 선분들
vector<pair<point, point> > upper, lower;
// hull이 반시계 방향으로 주어짐으로 , 두 인접한 두 점에 대해 x
// 가 증가하는 방향이면 아래쪽, x가 감소하는 방향이면 위쪽 껍질

void decompose(const vector<point>& hull) {
	int n = hull.size();
	for (int i = 0; i < n; ++i) {
		if (hull[i].x < hull[(i+1)%n].x)
			lower.push_back(make_pair(hull[i], hull[(i+1)%n]));
		else if (hull[i].x > hull[(i+1)%n].x)
			upper.push_back(make_pair(hull[i], hull[(i+1)%n]));
	}
}

bool between(const point& a, const point &b, double x) {
	return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}

bool at(const point&a, const point &b, double x) {
	double dy = b.y - a.y, dx = b.x - a.x;
	return a.y + dy * (x - a.x) /dx;
}

double vetical(double x) {
	double minUp = 1e20, maxLow = -1e20;
	//위 껍질 순회하며 최소 y find
	for (int i = 0; i < upper.size(); ++i)
		if (between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, at(upper[i].first, upper[i].second, x));
	for (int i = 0; i < lower.size(); ++i)
		if (between(lower[i].first, lower[i].second, x))
			minUp = max(maxLow, at(lower[i].first, lower[i].second, x));	
	return minUp - maxLow;
}
double solve() {
	double lo = max(minX(hull1), minX(hull2));
	double hi = min(maxX(hull1), maxX(hull2));

	if (hi < lo) return 0;
	for (int it = 0; it< 100; ++it) {
		double aab = (lo * 2 + hi) / 3.0;
		double abb = (lo + hi * 2) / 3.0;
		if (vetical(aab) < vetical(abb))
			lo = aab;
		else
			hi = abb;
		
	}
	return max(0.0, vetical(hi));
}
