#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const int maxN = 10;
vector<int> isFriend[maxN];
bool	isPair[maxN];
int T,N,M;

int getPair(int cur){
	int finish = 1;
	for (int i = 0; i < N; i++){
		if (!isPair[i]){
			finish = 0;
			break;
		}
	}
	if (finish) return (1);

	int ret = 0;
	if (isPair[cur]) return (getPair(cur + 1));
	for (int Next : isFriend[cur]){
		if (!isPair[Next] && !isPair[cur] && Next > cur){
			isPair[Next] = isPair[cur] = true;
			ret += getPair(cur + 1);
			isPair[Next] = isPair[cur] = false;
		}
	}
	return (ret);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> N >> M;
		//초기화
		memset(isFriend, 0, sizeof(isFriend));
		memset(isPair, 0, sizeof(isPair));
		for (int j = 0; j < M; j++){
			int studentX, studentY;
			cin >> studentX >> studentY;
			isFriend[studentX].push_back(studentY);
			isFriend[studentY].push_back(studentX);
		}
		cout << getPair(0) << '\n';
	}
}