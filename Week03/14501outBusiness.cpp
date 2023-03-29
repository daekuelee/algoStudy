#include <iostream>

using namespace std;

int dp[16];
typedef struct data{
	int t;
	int p;
}	dat;

dat input[16];
int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> input[i].t >> input[i].p;
	}
	dp[n] = input[n].t == 1 ? input[n].p : 0;
	for (int j = n - 1; j >= 1; j--){
		dp[j] = input[j].t + j <= n + 1 ? input[j].p : 0;
		int cur = dp[j];
		for (int k = j; k <= n; k++){
			if (input[j].t + j <= k)
				cur = max(cur, dp[j] + dp[k]);
		}
		dp[j] = cur;
	}
	int max = dp[1];
	for (int i = 1; i <=n; i++){
		if (max < dp[i])
			max = dp[i];
	}
	cout << max << '\n';
}