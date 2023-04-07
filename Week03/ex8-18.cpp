#include <iostream>

int n,m;
const int max_n = 100;
int cache[max_n][2 * max_n+1];

int  climb(int days, int curClimb){
	if (days == m) return (curClimb >= n ? 1 : 0);

	int &ret = cache[days][curClimb];
	if (ret != -1) return (ret);

	ret = climb(days+1, curClimb + 1) + climb(days+1, curClimb+2);
	return (ret);
}