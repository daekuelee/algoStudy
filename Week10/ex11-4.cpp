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

//path의 마지막 네 개의 도시 중 가운데 에 있는 두 도시의 순서를 바꿨을 때
// 걍러기 더 짧아 지는지 여부를 반환
bool pathSwapPruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int p = path[path.size()-4];
	int a = path[path.size()-3];
	int b = path[path.size()-2];
	int q = path[path.size()-1];
	return dist[p][a] + dist[p][q] > dist[p][b] + dist[a][q];
}

//시작 도시와 현재 도시를 제외한 path의 부분 경로를 뒤집어 보고 더 짧아 지는 지 확인한다
bool pathReversePruning(const vector<int>& path) {
	if ( path.size() < 4) return false;
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	for (int i = 0; i + 3 < path.size(); ++i) {
		int p = path[i];
		int a = path[i+1];
		if (dist[p][a] + dist[p][q] > dist[p][b] + dist[a][q])
			return true;
	}
	false;
}

vector<int> nearest[Max];
void	search(vector<int>& path, vector<bool>& visited,double currentLength){
	int here = path.back();
	if (best <= currentLength + simpleHeuristic(visited)) return ;
	if (path.size() == n) {
		best = min(best, currentLength + dist[here][0]);
		return ;
	}
	for (int i = 0; i < nearest[here].size(); ++i) {
		int next = nearest[here][i];
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