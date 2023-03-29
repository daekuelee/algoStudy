#include <iostream>
#include <cstring>

const int max_n = 1000;
int cache[max_n+1];
int n;
const int mod = 10007;
int tiling(int n){
	if (n == 1) return (1);
	if (n == 2) return (3);

	int &ret = cache[n];
	if (ret != -1) return (ret);
	ret = (tiling(n-1) + 2 * tiling(n-2)) % mod;
	return (ret);
}
using namespace std;
int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << tiling(n) << '\n';
}