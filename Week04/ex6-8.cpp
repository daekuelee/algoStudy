#include <iostream>
#include <vector>

using namespace std;
const int INF = 9999, SWITCHES = 10, CLOCKS =16;

const char linked[SWITCHES][CLOCKS+1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks);

void	push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++ clock)
		if (linked[swtch][clock] == ' x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
}

int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

	//이 스위치를 0번 누르는 경우 세번 누르는 경우까지 시도
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + solve(clocks, swtch+1));
		push(clocks, swtch);
	}
	//push(clocks,swtch)가 네번 호출되었으니 원래와 같은상태
	return (ret);
}