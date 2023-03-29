#include <iostream>
#include <string.h>
// nCr = n-1Cr + n-1Cr-1
const int max = 100;

int cache[max+1][max+1];

int n,r;

int bino2(int n, int r){
	//base case
	if (r == n || r == 0)
		return (1);
	
	int &ret = cache[n][r];
	if (ret != -1) return (ret);
	
	ret = bino2(n-1, r) + bino2(n-1, r-1);
	return (ret);
}
int main(void){

	memset(cache, -1, sizeof(cache));
	std::cin >> n >> r;
	std::cout << bino2(n, r) << '\n';
}