#include <iostream>
#include <cmath>

using namespace std;

int n;
const int max_n = 100;
const int End = 0;
int map[max_n][max_n];

bool jump(int x, int y){
	bool	canGo = false;

	//baseCase
	if (y >= n || x >= n) return (false);
	if (map[y][x] == End) return (true);

	int jumpSize = map[y][x];
	canGo = jump(x, y + jumpSize) || jump(x + jumpSize, y);
	return (canGo);
}

int main(void){

	memset(map, -1, sizeof(map));
	cin >> n;
	int y = 0;
	string s;
	for (int y = 0; cin >> s; y++){
		for (int x = 0; x < n; x++)
			map[y][x] = s[x] - '0';
	}
	string answer;
	answer = jump(0, 0) == true ? "Yes\n" : "No\n";
	cout << answer;
}