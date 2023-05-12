#include <iostream>

using namespace std;

const int Mod = 100000007;

string e, digits;
int n, m;
int cache[1<<14][20][2];
//과거 가격을 앞자리 부터 채움
//index 이번에 채울 자리의 인덱스
// taken 지금까지 사용한 자릿수들의 집합(비트마스크)
// mod ->m으로 나눈 나머지
// less 지금 까지 만든 가격이 이미 e 보다 작으면 1,아니면 0


int price(int index, int taken, int mod, int less) {
	if (index == n)
		return (less && mod == 0) ? 1 : 0;
	int &ret = cache[taken][mod][less];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = 0; next < n; ++next) {
		if ((taken & (1<<next)) == 0) {
			//과거 가격은 새 가격보다 항상 작아야함
			if (!less && e[index] < digits[next])
				continue;
			if (next > 0 && digits[next-1] == digits[next] && 
			(taken & (1<<(next-1))) == 0)
				continue;
			int nextTaken = taken | (1<<next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || e[index] > digits[next];
			ret += price(index+1, nextTaken, nextMod, nextLess);
			ret %= Mod;
		}
	}
	return ret;
}


int main(void){
	int T;
	cin >> T;
	for (int i =0; i< T; ++i){
		cin >> e >> m;
		n = e.size();
		memset(cache, -1, sizeof(cache));
		digits = e;
		sort(digits.begin(), digits.end());
		cout << price(0, 0, 0, 0) << '\n';
	}
}
