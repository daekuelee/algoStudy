#include <iostream>
#include <cstring>

const int max_k = 100000;
const int max_n = 100;
const int val = 1;
const int weight = 0;
int cache[max_n][max_k+1];
int input[max_n][2];
int n;
int k;
using namespace std;

int napBack(int curN, int curK){
	if (curN == n-1) {
		if (curK + input[curN][weight] <= k)
			return (input[curN][val]);
		else
			return (0);
	}

	int &ret = cache[curN][curK];
	if (ret != -1) return (ret);

	ret = napBack(curN+1, curK);
	if (curK + input[curN][weight] <= k)
		ret = max(ret, napBack(curN+1, curK + input[curN][weight]) + input[curN][val]);
	return (ret);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> input[i][weight] >> input[i][val];
	}
	cout << napBack(0, 0) << '\n';
}

