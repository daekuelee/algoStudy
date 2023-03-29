#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

const int maxS = 1000;
int cache[maxS+2][maxS+2];
string w,s;

const int dx[3] = {-1,-1,0};
const int dy[3] = {-1,0,-1};

int lcs(int wpos, int spos){
	if (wpos == 0 || spos == 0)
		return (0);
	int &ret = cache[wpos][spos];
	if (ret != -1) return (ret);
	ret = 0;
	
	if (w[wpos-1] == s[spos-1])
		return (ret = lcs(wpos-1, spos-1) + 1);
	for (int dir = 0; dir < 3; dir++){
		int nWpos = wpos + dy[dir];
		int sWpos = spos + dx[dir];
		ret = max(ret, lcs(nWpos, sWpos));
	}
	return (ret);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	memset(cache, -1, sizeof(cache));
	cin >> w >> s;
	cout << lcs(w.size(), s.size()) << '\n';
}