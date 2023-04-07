#include <iostream>
#include <cstring>

using namespace std;

string origin;
const int max_n = 10000;

int classify(int st, int end){
	//classify 가 사이즈 체크해야되는 지는 보류
	string	sub = origin.substr(st, end-st+1);
	if (sub == string(sub.size(), sub[0])) return 1;
	
	bool progress = true;
	for (int i = 0; i < sub.size()-1; i++)
		if (sub[i+1] - sub[i] != sub[1] - sub[0])
			progress = false;
	if (progress && abs(sub[1]-sub[0])) return 2;

	bool alter = true;
	for (int i = 0; i < sub.size(); i++)
		if (sub[i] != sub[i%2])
			alter = false;
	if (alter) return 4;
	if (progress) return 5;
	return 10;
}

int cache[max_n+2]; // 현재 문자열 위치에 대한 계산값 캐싱
// memo(begin) = min(L=3,5) {memo(begin+L) + classfiy(begin) }
const int INF = 986754321;

int memorize(int begin){
	if (begin == origin.size()) return (0);

	int &ret = cache[begin];
	if (ret != -1) return (ret);
	
	ret = INF;
	for (int L = 3; L <= 5; L++)
		if (begin + L <= origin.size())
			ret = min(ret, memorize(begin + L) + 
							classify(begin, begin+L-1));
	return (ret);
}

int main(void){
	ios::sync_with_stdio(0);

	memset(cache, -1, sizeof(cache));
	cin >> origin;
	cout << memorize(0) << '\n';
}