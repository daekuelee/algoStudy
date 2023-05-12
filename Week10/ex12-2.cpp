#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
//두기지 사이의 거리 미리 계산
const int max_n = 100;
double dist[max_n+1][max_n+1];
//거리가 d 이하인 기지들만 연결했을 떄 모든 기지가 연결되는지 반환
bool decision(double d) {
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> Q;
	Q.push(0);
	int seen = 0;
	while (!Q.empty()){
		int here = Q.front();
		Q.pop();
		++seen;
		for (int there = 0; there < n; ++there)
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				Q.push(there);
			}
	}
	return seen == n;
}

//모든 기지를 연결할 수 있는 최소 d 반환
double optimize() {
	double lo = 0, hi = 1416.00;
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2;
		//mid가 가능하다면 더 좋은 (작은 답을) 찾느다
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}