#include <iostream>
#include <cstring>
// 1000000000
// 2147483647
// INT32_MAX
// nCm;
// nCm = n-1Cm + n-1Cm-1;
const int max_n = 100;
const int INF = 1000000000 + 1;
int cache[max_n * 2 + 1][max_n+1];
bool	exist;
char	answer[max_n * 2+1];
using namespace std;

int N,M,K;
int comb(int n, int m){
	if (n == m || m == 0) return (1);

	int &ret = cache[n][m];
	if (ret != -1) return (ret);
	ret = comb(n-1, m) + comb(n-1, m-1);
	if (ret > INF) ret = INF;
	return (ret);
}

void checkOne(int n, int m, int rest){
	int C = comb(n+m-1, n-1);
	if (rest <= C && n > 0){
		cout << 'a';
		checkOne(n-1, m, rest);
	}
	else if (m > 0){
		cout << 'z';
		checkOne(n, m-1, rest-C);
	}
}
int main(void){
	memset(cache,-1,sizeof(cache));
	cin >> N >> M >> K;

	if (comb(N+M, N) < K) {
		cout << "-1\n";
		return (0);
	}
	checkOne(N,M,K);
	cout << '\n';
}