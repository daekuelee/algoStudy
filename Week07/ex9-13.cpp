#include <iostream>
#include <vector>

using namespace std;

const int Max = 100000000+1;
//length[i] = X나 Y를 i번 치환한 후의 길이
int length[51];
void precalc() {
	length[0] = 1;
	for (int i = 1; i <= 50; ++i)
		length[i] = min(Max, length[i-1] * 2 + 2);
}
const string ExpandX = "X+YF";
const string ExpandY = "FX-Y";
//drangonCurve를 generations 진화 시킨 결과에서 skip번쨰 문자를 반환
char expand(const string& dragonCurve, int generations, int skip) {
	if (generations == 0) {
		assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}
	for (int i =0; i< dragonCurve.size(); ++i){
		//문자열이 확장되는 경우
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= length[generations])
				skip -= length[generations];
			else if (dragonCurve[i] == 'X')
				return expand(ExpandX, generations-1, skip);
			else
				return expand(ExpandY, generations-1, skip)l
		}
			//확장 되지 않지만 건너 뛰어야 할 경우
		else if (skip > 0)
			--skip;
			//답찾음
		else
			return dragonCurve[i];
	}
	return '#'; //이줄은 수행되지 않음

}