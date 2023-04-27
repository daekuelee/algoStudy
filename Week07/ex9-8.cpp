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
void generate3(int n, int m, string s) {
	if (skip < 0) return ;

	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip;
		return ;
	}
	if (bino[n+m][n] <= skip) {
		skip -= bino[n+m][n];
		return ;
	}
	if (n > 0) generate3(n-1,m,s+"-");
	if (m > 0) generate3(n, m-1, s+"o");
}