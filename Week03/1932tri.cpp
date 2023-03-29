#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int dp[502][502];
vector<int> v[501];

int main(void){
	ios::sync_with_stdio(0); cin.tie();

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < i; j++){
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}
	dp[1][0] = v[1][0];
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < i; j++){
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + v[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++){
		res = max(res, dp[n][i]);
	}
	cout << res << '\n';
}