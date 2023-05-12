#include <iostream>
#include <vector>

using namespace std;

//결정 문제 : 정렬 되어 있는 locations중  cameras를 선택해 모든 카메라
//간의 간격이  gap 이상이 되는 방법이 있는지를 반환

bool decision(const vector<double>& location, int cameras, 
double gap) {
	//카메라를 설치 할 수 있을 떄 마다 설치하는 탐욕적 알고리즘
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(); ++i) {
		if (limit <= location[i]) {
			++installed;
			//location[i] + gap이후는 되어야 카메라 설치 가능
			limit = location[i] + gap;
		}
	}
	//결과적으로 cameras 이후는 되어야 카메라를 설치할수 있음
	return installed >= cameras;
}

//최적화 문제:  정렬되어 있는 locations 중 cameras를 선택해 최소 간격을 최대화
double optimize(const vector<double>& location, int cameras) {
	double lo = 0, hi = 241;
	//반복 불변식 : decision(lo)&& !decision(hi)
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2.0;
		//간격이 mid이상 되도록 할 수 있으면 답은 mid,hi에 있다
		if (decision(location, cameras, mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}