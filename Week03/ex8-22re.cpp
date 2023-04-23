#include <iostream>
#include <vector>
using namespace std;

int n, d, p, q;

const int max_n = 50;
bool connected[max_n+1][max_n+1];
int degree[max_n+1];

double search(vector<int> &path){
	//base case finish
	if (path.size() == d+1) {
		if (!connected[path.back()][q]) return 0;
		double ret = 1.0;
		for (int i = 0; i < path.size() - 1; i++)
			ret /= degree[path[i]];
		return (ret);
	}

	double ret = 0;
	const int cur = path.back();
	for (int next = 0; next < n; next++){
		if (connected[cur][next]) {
			path.push_back(next);
			ret += search(path);
			path.pop_back();
		}
	}
	return (ret);
}