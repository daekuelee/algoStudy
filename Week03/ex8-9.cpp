#include <iostream>

const int max_n = 100;
int cache[max_n][max_n];
int triangle[max_n][max_n];
int n;

int path(int x, int y){
	//base
	if (y == n-1)
		return (triangle[y][x]);
	
	int &ret = cache[y][x];
	if (ret == -1) return (ret);

	ret = std::max(path(x,y+1), path(x+1,y+1)) + triangle[y][x];
	return (ret);
}