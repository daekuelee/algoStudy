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