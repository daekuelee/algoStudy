#include <iostream>
#include <vector>
using namespace std;

int n, d, p, q;

const int max_n = 50;
bool connected[max_n+1][max_n+1];
int degree[max_n+1];
double search(vector<int> &path) {
	//base case : end days
	if (path.size() == d+1) {
		if (path.back() != q) return (0.0);
		double ret = 1.0;
		for (int i = 0; i + 1 < path.size(); ++i)
			ret /= degree[path[i]];
		return (ret);
	}
	double ret = 0;

	for (int there = 0; there < n; there++){
		if (connected[path.back()][there]) {
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
	}
	return (ret);
}