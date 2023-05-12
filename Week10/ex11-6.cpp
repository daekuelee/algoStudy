#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int CachedDepth = 5;
const double INF = 1e200;
const int Max = 300;
int n;
double dist[Max][Max];
using namespace std;
double minEdge[Max];
double best;// dp(here, visited) = cache[here][남은 도시의 수][visited]
map<int, double> cache[Max][CachedDepth+1];
//here 현재 위치
// visited 각 도시의 방문 여부
double dp(int here, int visited) {
	//base case 시작 위치로 돌아감
	if (visited == (1<<n)-1) return dist[here][0];

	int remaining = n - __builtin_popcount(visited);
	double& ret = cache[here][remaining][visited];
	if (ret > 0) return ret;
	ret = INF;
	for (int next = 0; next <n; ++next) {
		if (visited & (1<<next)) continue ;
		ret = min(ret,
				dp(next, visited + (1<<next)) + dist[here][next]);
	}
	return ret;
}

vector<int> nearest[Max];
void	search(vector<int>& path, vector<bool>& visited,double currentLength){
	int here = path.back();
	if (best <= currentLength + simpleHeuristic(visited)) return ;
	if (path.size() == n) {
		best = min(best, currentLength + dist[here][0]);
		return ;
	}

// 기저사례 남은 도시가 ca뎁스에 도착하면 dp로 바꿈
	if (path.size() + CachedDepth >= n) {
		best = min(best, currentLength + dp(path.back(), visited));
		return;
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
	//
	for (int i = 0; i < Max;++i)
		for (int j = 0; j <= CachedDepth; ++j)
			cache[i][j].clear();
	edges.clear();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i ; ++ j)
			edges.push_back(make_pair(dist[i][j], make_pair(i,j)));
	sort(edges.begin(), edges.end());
	best = INF;
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;
	search(path, visited, 0);
	return best;
}