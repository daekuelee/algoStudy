#include <iostream>
#include <vector>

using namespace std;

const int Max = 2000000000+1;
int n;
const int max_n = 500;
int cacheLen[max_n+1], cacheCnt[max_n+1], S[max_n];
// S[start]에서 시작하는 증가 부분수열중 최대 길이 반환
int lis3(int start) {
	int & ret = cacheLen[start + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; ++next)
		if (start == -1 || S[start] < S[next])
			ret = max(ret, lis3(next) + 1);
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

//S[start]에서 시작하는 Lis 중 사전순으로 skip개 건너뛴 수열을 lis에 저장
void reconstruct(int start, int skip, vector<int>& lis) {
	//1. S[start]는 항상 Lis에 포함
	if (start != -1) lis.push_back(S[start]);
	//2. 뒤에 올 수 있는 숫자들과 위치의 목록을 만든다
	// (숫자, 숫자의 위치)
	vector<pair<int,int> > followers;
	for (int next = start+1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) &&
		lis3(start) == lis3(next) + 1)
			followers.push_back(make_pair(S[next], next));
	}
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); ++i) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip)
			skip -= cnt;
		else {
			//다음 숫자는 S[idx]임을 암
			//4.재귀호출
			reconstruct(idx, skip, lis);
			break ;
		}
	}
}