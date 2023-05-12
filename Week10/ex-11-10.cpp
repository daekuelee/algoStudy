#include <iostream>
#include <vector>

using namespace std;
int n,m;
const int max_n = 50;
vector<int> canEat[max_n], eaters[max_n];
int best;

//i번 친구가 먹을수 있는 음식수 -> edible[i]
void search(vector<int>& edible, int chosen) {
	if (chosen >= best) return;

	//아직 먹을 음식이 없는 처음 친구를 찾는다j
	int first = 0;
	while (first < n && edible[first] > 0) ++first;

	if (first == n) {best = chosen; return;}
	//이 친구가 먹을 수 있는 음식 하나 만들기
	for (int i = 0; i < canEat[first].size(); ++i) {
		int food = canEat[first][i];
		for (int j = 0; j < eaters[food].size(); ++j)
			edible[eaters[food][j]]++;
		search(edible, chosen+1);
		for (int j = 0; j < eaters[food].size(); ++j)
			edible[eaters[food][j]]--;
	}
}