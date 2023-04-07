#include <iostream>

using namespace std;

const int max_n = 100;
int cache[max_n+1][max_n+1];
int A[max_n],B[max_n];
int n,m;
int jLis(int Apos, int Bpos){
	int &ret = cache[Apos+1][Bpos+1];
	if (ret != -1) return (ret);

	ret = 2;
	long long a = (Apos == -1 ? INT64_MIN : A[Apos]);
	long long b = (Bpos == -1 ? INT64_MIN : B[Bpos]);
	long long maxE = max(a,b);
	for (int next = Apos+1; next < n; next++){
		if (maxE < A[next])
			ret = max(ret, jLis(next, Bpos) + 1);
	}
	for (int next = Bpos+1; next < m; next++){
		if (maxE < B[next])
			ret = max(ret, jLis(Apos, next) + 1);
	}
	return (ret);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>> n>> m;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) cin >> B[i];
	cout << jLis(-1,-1)-2<<'\n';
}