#include <iostream>

using namespace std;
const int max_n = 15;
int k;
string word[max_n];
int cache[max_n][1<<max_n], overlap[max_n][max_n];

int restore(int last, int used) {
	//base
	if (used == (1<<k)-1) return 0;
	
	int &ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; next++){
		if ((used & (1<<next) == 0)) {
			int cand = overlap[last][next] + 
					restore(next, used + (1<<next));
			ret = max(ret, cand);
		}
	}
	return (ret);
}

//처음 호출 시 last는 recover()가 최댓값을 반환한 시작 단어로,
//used는 1<<last로 둔다
string reconstruct(int last, int used) {
	//base
	if (used == (1<<k)-1) return "";
	//find
	for (int next = 0; next < k; ++next) {
		//next 가 이미 사용되었으면 제외
		if (used & (1<<next)) continue ;
		//next를 사용했을 경우의 답이 최적해와 같다면 next를 사용
		int ifUsed = restore(next, used + (1<<next)) 
			+ overlap[last][next];
		if (restore(last, used) == ifUsed)
			return (word[next].substr(overlap[last][next]) +
				reconstruct(next, used + (1<<next)));
	}
	return "*****ooops****";
}