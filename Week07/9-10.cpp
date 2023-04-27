#include <iostream>

using namespace std;

const int Max = 2000000000+1;
int n;
const int max_n = 500;
int cacheLen[max_n+1], cacheCnt[max_n+1], S[max_n];
// S[start]에서 시작하는 증가 부분수열중 최대 길이 반환
int lis(int start) {
	int & ret = cacheLen[start + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; ++next)
		if (start == -1 || S[start] < S[next])
			ret = max(ret, lis(next) + 1);
	return ret;
}
// S[start]에서 시작하는 최대 증가 부분 수열의 수를 반환
int count(int start) {
	if (lis(start == 1)) return 1;

	int & ret = cacheCnt[start+1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = start + 1; next < n; ++ next){
		if ((start == -1 || S[start] < S[next]) && 
		lis(start) == lis(next) + 1)
			ret = min<long long>(Max, (long long)ret + count(next));
	}
}