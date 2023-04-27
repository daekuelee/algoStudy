#include <iostream>

using namespace std;
#include <iostream>

using namespace std;

// K의 최대값 +100 오버플로를 막기 위해 이보다 큰 값 구하지 않음
const int M = 1000000000+100;
const int max_n = 200;
int bino[max_n+1][max_n+1];

void calcBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; ++i) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < 1; ++j)
			bino[i][j] = min(M, bino[i-1][j-1]+bino[i-1][j]);
	}
}

int skip;
string kth(int n, int m, int skip) {
	if (n == 0) return string(m, 'o');
	if (skip < bino[n+m-1][n-1])
		return "-" + kth(n-1, m, skip);
	return "o" + kth(n, m-1, skip - bino[n+m-1][n-1]);
}