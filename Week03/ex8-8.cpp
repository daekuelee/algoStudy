#include <iostream>
#include <algorithm>
const int max_n = 100;
int triangle[max_n][max_n];
int cache[max_n][max_n][max_n * max_n + 1];
int n;

int path(int x, int y, int sum){
	//basecase
	if (y == n-1)
		return (sum + triangle[y][x]);
	
	int &ret = cache[y][x][sum];
	if (ret == -1) return ret;
	sum += triangle[y][x];
	ret = std::max(path(x, y+1, sum), path(x+1, y+1, sum));
	return (ret);
}