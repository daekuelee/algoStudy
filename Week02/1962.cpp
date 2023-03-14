#include <iostream>
#include <deque>
using namespace std;
char map[64][64];
int n;

// basic ->  압축가능하면 압축 출력 아니면 (내용물)
bool	isCompress(int size, int x, int y){
	char	first = map[y][x];

	if (size == 1) return (true); //1개면 압축 가능하다고 생각

	for (int i = y; i < size + y; i++){
		for (int j = x; j < size + x; j++){
			if (map[i][j] != first) return (false);
		}
	}
	return (true);
}
void	quadTree(int size, int x, int y){
	//압축 가능하다면 처음꺼 하나만 출력
	if (isCompress(size, x, y)){
		cout << map[y][x];
		return ;
	}
	else {
		// 아니면 분할 해서 출력 
		cout << '(';
		int nSize = size / 2;
		quadTree(nSize, x, y);
		quadTree(nSize, x + nSize, y);
		quadTree(nSize, x, y + nSize);
		quadTree(nSize, x + nSize, y + nSize);
		cout << ')';
	}
}
int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			map[i][j] = s[j];
	}
	quadTree(n, 0, 0);
	cout << '\n';
}