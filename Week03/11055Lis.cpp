#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int n;
const int max_n = 1000;
int cache[max_n + 1];
int choices[max_n + 1];
int S[max_n];
int lis(int start){
	int &ret = cache[start];
	if (ret != -1) return (ret);

	ret = S[start];
	for (int next = start + 1; next < n; next++){
		if (S[start] < S[next])
			ret = max(ret, lis(next) + S[start]);
	}
	return (ret);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> S[i];

	int Max = lis(0);
	for (int i = 1; i < n; i++)
		Max = max(Max, lis(i));
	cout << Max << '\n';
}