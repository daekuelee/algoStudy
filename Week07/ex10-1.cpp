#include <iostream>
#include <vector>

using namespace std;

//각 회의는 begin-end구간 동안 회의실 사용
int n;
const int max_n = 100;
int start[max_n], ed[max_n];
int schedule() {
	//일찍 끝나느 순서대로 정렬
	std::vector<std::pair<int, int> > order;
	for (int i = 0; i < n; ++i)
		order.push_back(make_pair(ed[i], start[i]));
	sort(order.begin(), order.end());

	int fastest = 0, selected = 0;
	for (int i = 0; i < order.size(); ++i) {
		int meetingBegin = order[i].second;
		int meetingEnd =order[i].first;
		if (fastest <= meetingBegin) {
			fastest = meetingEnd;
			selected++;
		}
	}
	return selected;
}