#include <iostream>
#include <vector>

using namespace std;

// mask에 속한 원소들의 개수를 반환한다
int getSize(int mask);
//mask 에 속한 원소들의 합을 반환한다.
int getSum(int mask);
//연속된 len칸의 합이  sum 이고 이칸들에 이미 쓰여진 수 의 집합 known
// 나머지 칸에 들어 갈 수 있는 숫자들ㅇ ㅢ 집합을 반환
int getCandidates(int len, int sum, int known) {
	//조건에 부합하는 집합들의 교집합
	int allSets = 0;
	// 1~9의 부분집합을 모두 생성하고 그중 
	for (int set = 0; set < 1024; set += 2)
		//known을 포함하고 크기가 len이며 합이 sum인 집합을 모두 찾느다
		if ( (set & known) == known && getSize(set) == len
		&& getSum(set) == sum)
			allSets |= set;
	//known에 이미 속한 숫자들은 답에서 제외한다
	return allSets & ~known;
}