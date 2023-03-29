#include <iostream>
#include <math.h>

using namespace std;
int dp[1002][3];
int input[1002][3];
int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin>> input[i][0] >> input[i][1] >> input[i][2];
	}
	dp[1][0] = input[1][0];
	dp[1][1] = input[1][1];
	dp[1][2] = input[1][2];
	for (int i = 2; i <= n; i++){
		dp[i][0] = input[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = input[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = input[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
}