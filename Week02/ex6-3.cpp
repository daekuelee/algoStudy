#include <cstdlib>
#include <iostream>

using namespace std;

const int max_n = 10; // 격자 최대
int N;
string	Find;
char	Given[max_n][max_n];
const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool	hasWord(int cur, int x, int y){
	if (cur == Find.size()) return (true);
	if (x < 0 || y < 0 || x > N || y > N) return (false);
	if (Find[cur] != Given[y][x]) return (false);

	for (int dir = 0; dir < 8; dir++){
		int nX = x + dx[dir];
		int nY = y + dy[dir];
		if (hasWord(cur + 1, nX, nY))
			return (true);
	}
	return (false);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Find;
	for (int y = 0; y < N; y++){
		for (int x = 0; x < N; x++){
			char tmp;
			cin >> tmp;
			if (tmp == '\n')
				cin >> tmp;
			Given[y][x] = tmp;
		}
	}
	for (int y = 0; y < N; y++){
		for (int x = 0; x < N; x++){
			if (Given[y][x] == Find[0]){
				if (hasWord(0, x, y)){
					cout << "Yes\n";
					return (0);
				}
			}
		}
	}
	cout << "NO\n";
}