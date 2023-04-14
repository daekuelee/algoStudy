#include <iostream>
#include <vector>

using namespace std;
int n;
const int MAX = 10;
const double INF = 10e10; 
double dist[MAX][MAX]; // 두도시간의 거리 저장 배열
//path 지금 까지 만든 경로
// visitied  각 도시 방문 여부


double shortestPath(vector<int>& path, vector<bool>& visited, 
double currentLength) {
	if (path.size() == n)
		return currentLength + dist[path[0]][path.back()];
		
	double ret = INF;
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue ;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		double cand = shortestPath(path, visited, currentLength + 
		dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return (ret);
}