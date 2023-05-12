#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

// mask에 속한 원소들의 개수를 반환한다
int getSize(int mask);
//mask 에 속한 원소들의 합을 반환한다.
int getSum(int mask);
//연속된 len칸의 합이  sum 이고 이칸들에 이미 쓰여진 수 의 집합 known
// 나머지 칸에 들어 갈 수 있는 숫자들ㅇ ㅢ 집합을 반환
//candidtaets[len][sum][known];
int candidates[10][46][1024];

const int max_n = 10;
void generateCandidates() {
	memset(candidates, 0, sizeof(candidates));

	for (int set = 0; set < 1024; set += 2) {
		int l = getSize(set), s = getSum(set);
		//set 의 모든 부분 집합에 대해 candidate를 갱신한다
		int subset = set;
		while (true) {
			//숫자 하나의 합이 s이고 이미 subset숫자가 쓰여 있을떄
			//전체 숫자의 집합이  set이 되도록 나머지 숫자 집어 넣음
			candidates[l][s][subset] |= (set & ~subset);
			if (subset = 0) break;
			subset = (subset - 1) & set;
		}
	}
}

//게임판의 정보
//color:각 칸의 색깔 0-흑 1 백
// value  각 흰 칸에 쓴 숫자( 아직 쓰지 않은 숫자 0)
// hint 각 칸에 해당하는 두 힌트의 번호
int n, color[max_n][max_n], value[max_n][max_n];
int hint[max_n][max_n][2];
//각 힌트의 정보
// sum : 힌트 칸에 쓰인 숫자
// length : 힌트 칸에 해당하는 흰 칸 의 수
// known: 힌트 칸에 해당하는 흰 칸에 쓰인 숫자들의 집합
int q, sum[max_n*max_n], length[max_n*max_n];
int known[max_n*max_n];

//(y,x)에 val을 쓴다
void put (int y, int x, int val) {
	for (int h =0; h < 2; ++h)
		known[hint[y][x][h]] += (1<<val);
	value[y][x] = val;
}
// 지운다
void remove(int y, int x, int val) {
	for (int h = 0; h < 2; ++h)
		known[hint[y][x][h]] -= (1<<val);
	value[y][x] = 0;
}
//힌트 번호가 주어질 떄 후보의 집합을 반환하다
int getCandHint(int hint) {
	return candidates[length[hint]][sum[hint]][known[hint]];

}
//좌표가 주어질떄 해당 칸에 들어갈수 있는 후보의 집합 반환
int getCandCoord(int y, int x) {
	return getCandHint(hint[y][x][0]) &
		getCandHint(hint[y][x][1]);
}
//value[][]에 적힌값 출력
void printSolution();

const int white = 0;
bool search() {
	//아직 숫자를 쓰지 않은 흰칸 중 후보의 수가 최소인 칸을 찾는다
	int y = -1, x = -1, minCands = 1023;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (color[i][j] == white && value[i][j] == 0) {
				int cands = getCandCoord(i, j);
				if (getSize(minCands) > getSize(cands)) {
					minCands = cands;
					y = i; x =j;
				}
			}
			//이칸에 들어갈 숫자 없음
	if (minCands == 0) return false;
	//모든 칸 채워짐
	if (y == -1) {
		printSolution();
		return true;
	}
	//숫자를 하나 씩 채워 보자
	for (int val = 1; val <= 9; val)
		if (minCands & (1<<val)) {
			put(y,x,val);
			if (search()) return true;
			remove(y,x,val);
		}
	return false;
}