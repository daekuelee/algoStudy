#include <iostream>
#include <cstring>
using namespace std;

const int max_n = 100;
int S[max_n];
int cache[max_n+1];
int n;
int lis(int start){
	int &ret = cache[start+1];
	if (ret != -1) return (ret);


	ret = 1;
	for (int next = start + 1; next < n; next++){
		if (start == -1 || (S[start] < S[next]))
			ret = max(ret, lis(next)+1);
	}
	return (ret);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; i++)
		cin>>S[i];
	cout << lis(-1)-1<<'\n';
}