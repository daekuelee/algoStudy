#include <iostream>
#include <string.h>
#include <math.h>
int N;
int W[16][16];
int dp[16][1 << 16];
const int Impossible = 1000000000;
using namespace std;
// Subproblem 내가 현재 어느 마을에 있는데 지금 어디어디를 방문 했고 시작 점으로 돌아가는 
// 최단 경로의 수 → 현재 가능한 경로 중 min(어느마을로 가는 경로 + 어느마을의 최단 경로);
int Tsp(int curr, int visited){
	int &ret = dp[curr][visited];

	if (ret != -1) return (ret);
	if (visited == (1 << N) - 1){
		if (W[curr][0] == 0) return (Impossible);
		else return (W[curr][0]);
	}
	ret = Impossible;
	for (int i = 0; i < N; i++){
		if (W[curr][i] == 0 || visited & (1 << i)) continue ;
		int next = Tsp(i, visited | (1 << i));
		ret = min(ret, next + W[curr][i]);
	}
	return (ret);
}
int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			cin>>W[i][j];
	}
	cout << Tsp(0, 1) << '\n';
}