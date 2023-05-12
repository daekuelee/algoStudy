#include <iostream>
#include <vector>

const double INF = 1e200;
const int Max = 300;
int n;
double dist[Max][Max];
using namespace std;
double minEdge[Max];
double best;
//Simplest heuristic
double simpleHeuristic(vector<bool>& visited) {
	double ret = minEdge[0];
	for (int i = 0; i < n; ++i)
		if (!visited[i])
			ret += minEdge[i];
	return ret;
}


void	search(vector<int>& path, vector<bool>& visited,double currentLength){
	int here = path.back();
	if (best <= currentLength + simpleHeuristic(visited)) return ;
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
	for (int i = 0; i < n; ++i) {
		minEdge[i] = INF;
		for (int j = 0; j < n; ++j)
			if(i != j) minEdge[i] = min(minEdge[i], dist[i][j]);
	}
	best = INF;
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;
	search(path, visited, 0);
	return best;
}