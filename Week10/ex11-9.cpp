#include <iostream>
#include <vector>

using namespace std;
int n,m;
const int max_n= 50;
//eaters[food] = food를 먹을 수 있는 친구들의 번호
vector<int> eaters[max_n];
int best;
// food 이번에 고려해야 할 음식
//edible 지금 까지 고른 음식 중 i 번 친구가 먹을 수 있는 음식 수
//chosen 지금 까지 고른 음식 수
void slowSearch(int food, vector<int>& edible, int chosen) {

	if (chosen >= best) return;
	//base 모든 음식에대해 만들지 여부를 결정하면
	// 최적해 갱신할지 정함
	if (food == m) {
		if (find(edible.begin(), edible.end(), 0) == edible.end())
			best = chosen;
				return ;
	}
	//no make food
	slowSearch(food+1, edible, chosen);

	for (int j = 0; j < eaters[food].size(); ++ j)
		edible[eaters[food][j]]++;
	slowSearch(food+1, edible, chosen+1);
	for (int j = 0; j < eaters[food].size(); ++ j)
		edible[eaters[food][j]]--;
}