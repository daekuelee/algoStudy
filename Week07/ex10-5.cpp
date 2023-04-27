#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double pi = 2.0 * acos(0);
int n;
const int max_n = 100;
const int INF = 987654321;
double y[max_n], x[max_n], r[max_n];
pair<double, double> ranges[max_n];
void converToRange() {
	for (int i =0; i < n; ++i) {
		double loc = fmod(2*pi + atan2(y[i],x[i]), 2*pi);
		double range = 2.0 * asin(r[i] / 2.0 / 8.0);
		ranges[i] = make_pair(loc-range, loc+range);
	}

}

int solveLinear(double begin, double end) {
	int used = 0, idx = 0;

	while (begin < end) {

		double maxCover = -1;
		while (idx < n && ranges[idx].first <= begin){
			maxCover = max(maxCover, ranges[idx].second);
			idx++;
		}
		//덮을 구간을 찾지 못한 경우
		if (maxCover <= begin) return INF;
		//선분의 덮인 부분을 잘라낸다
		begin = maxCover;
		++used;
	}
	return used;
}
int solveCircular() {
	int ret = INF;
	
	sort (ranges, ranges+n);
	for (int i = 0; i < n; ++i) {
		if (ranges[i].first <= 0 || ranges[i].second >= 2*pi) {
			double begin = fmod(ranges[i].second, 2*pi);
			double end = fmod(ranges[i].first+2*pi, pi);
			ret = min(ret, 1+ solveLinear(begin, end));
		}
	}
	return ret;
}