#include <iostream>

using namespace std;

const int Empty = -987654321;
int n;
const int max_n =50;
int board[max_n];
int cache[max_n][max_n];
int play(int left, int right) {
	//base 
	if (left > right) return 0; 
	int & ret = cache[left][right];
	if (ret!= Empty) return ret;

	ret = max(board[left]-play(left+1, right),
		board[right] - play(left, right-1));
	
	if (right-left+1 >= 2) {
		ret = max(ret, -play(left+2, right));
		ret = max(ret, -play(left, right-2));
	}
	return ret;
}