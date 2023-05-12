#include <iostream>
#include <vector>

using namespace std;
const double INF = 1e200;
const int Max = 300;
int n;
double dist[Max][Max];
using namespace std;
double minEdge[Max];
double best;

struct DisjointSet {
	//n개의 원소로 구성된 집합자료 구조
	DisjointSet(int n);
	//부모
	int find(int here);

	bool merge(int a, int b);
};

// 모든 도시간의 도로를 길이 순으로 정렬해 저장
vector<pair<double,pair<int, int> > > edges;

//here와 시작점, 아직 방문하지 않는 도시들을 모두 연결하는 MST 찾음
double mstHeuristic(int here, const vector<bool>& visited) {
	// Kruskals
	DisjointSet sets(n);
	double taken = 0;
	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].second.first, b = edges[i].second.second;
		if (a != 0 && a != here && visited[a]) continue;
		if (b != 0 && b != here && visited[b]) continue ;
		if (sets.merge(a, b))
			taken += edges[i].first;
	}


	return taken;
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
	//
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