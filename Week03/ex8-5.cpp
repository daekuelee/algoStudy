#include <iostream>
#include <cmath>

using namespace std;

int n;
const int max_n = 100;
const int End = 0;
int map[max_n][max_n];
int cache[max_n][max_n];

bool jump(int x, int y){
	//baseCase
	if (y >= n || x >= n) return (false);
	if (y == n-1 && x == n-1) return (true);

	int &ret = cache[y][x];
	if (ret != -1) return (ret);
	int jumpSize = map[y][x];
	ret = jump(x, y + jumpSize) || jump(x + jumpSize, y);
	return (ret);
}

int main(void){

	memset(cache, -1, sizeof(cache));
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