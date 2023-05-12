#include <iostream>
#include <vector>

using namespace std;

const double INF = 1e200;
const int Max = 300;
int n;
double dist[Max][Max];

//최적해 현재
double best;
//path 현 경로
//visited 방문
//currentLength

void	search(vector<int>& path, vector<bool>& visited,double currentLength){
	int here = path.back();
	if (path.size() == n) {
		best = min(best, currentLength + dist[here][0]);
		return ;
	}
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue;
		path.push_back(next);
		visited[next] = true;
		search(path, visited, currentLength+dist[here][next]);
		visited[next] = false;
		path.pop_back();
	}
}
double solve() {
	best = INF;
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;
	search(path, visited, 0);
	return best;
}