#include <iostream>

using namespace std;

const int INF = 1e13;
const int Max = 1000000;
int n, dist[Max][Max];
double cache[Max][1<<Max];

double shortestPath(int here, int visited) {
	//기저사례 모든 도시를 다 방문했을떄 0번 도시로 돌아감
	if (visited == (1<<n) -1) return dist[here][0];
	double &ret = cache[here][visited];
	if (ret >= 0) return ret;
	ret =INF;
	for (int next = 0; next < n; ++ next) {
		if (visited & (1<<next)) continue;
		double canDo = dist[here][next] +
						shortestPath(next, visited + (1<<next));
		ret = min(ret, canDo);
	}
	return ret; 
}