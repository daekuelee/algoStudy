#include <iostream>
#include <vector>

using namespace std;
//turn이 한줄을 만들었는지를 반환
bool isFinished(const vector<string>& board, char turn) {
    // 행, 열 검사
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) return true; // i번째 행이 turn으로 다 채워져 있음
        if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn) return true; // i번째 열이 turn으로 다 채워져 있음
    }
    // 대각선 검사
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) return true; // 왼쪽 위에서 오른쪽 아래 대각선이 turn으로 다 채워져 있음
    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) return true; // 오른쪽 위에서 왼쪽 아래 대각선이 turn으로 다 채워져 있음

    return false;
}
// 틱택토 게임판이 주어질 떄 [0, 19682]의 범위 정수 반환
int bijection(const vector<string>& board) {
	int ret = 0;
	for (int y = 0; y<3;++y)
		for (int x =0; x<3; ++x) {
			ret = ret *3;
			if (board[y][x] == 'o') ++ret;
			else if (board[y][x] == 'x') ret += 2;
	}
	return ret;
}

int cache[19683];

int canWin(vector<string>& board, char turn) {
	// 기저 사례: 마지막에 상대가 둬서 한줄이 만들어진 경우
	if (isFinished(board, 'o'+'x'-turn)) return -1;
	int & ret= cache[bijection(board)];
	if (ret!= -2) return ret;

	int minvalue = 2;
	for (int y = 0; y < 3; ++y)
		for (int x =0; x< 3; ++ x)
			if (board[y][x] == '.') {
				board[y][x] = turn;
				minvalue = min(minvalue, canWin(board, 'o'+'x'-turn));
				board[y][x] = '.';
			}
	//플레이할 수 없거나 어떻게 해도 비기는 것이 최선
	if (minvalue == 2 || minvalue == 0) return ret = 0;

	return ret = -minvalue;
}