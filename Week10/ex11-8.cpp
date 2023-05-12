#include <iostream>
#include <vector>

using namespace std;

//블록의 각 회전 형태를 상태 좌표로 저장할 자료구조
vector<vector<pair<int, int> > > rotations;
//블록 크기
int blockSize;
// 2차원 배열 arr을 시계 방향으로 돌린결과 반환
vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0; j < arr[0].size(); ++j)
			ret[j][arr.size()-i-1] = arr[i][j];
	return ret;
}
//block의 네가지 회전 형태를 만들고 이들을 상대 좌표의 목록으로 변환
void generateRotations(vector<string> block) {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; ++rot) {
		int originY = -1, originX = -1;
		for (int i = 0; i < block.size(); ++i)
			for (int j = 0; j < block[i].size(); ++j)
				if (block[i][j] == '#') {
					if (originY == -1) {
						//가장 윗줄 맨 왼쪽 점 -- origin
						originY = i;
						originX = j;
					}
					//각 칸의 위치를 원점으로 부터의 상대좌표로 표현
					rotations[rot].push_back(make_pair(i - originY,
													j - originX));
					}
		//블록을 시계 방향으로 회전
		block = rotate(block);
	}
	//네가지 회전 형태 중 중복이 있을 경우 이를 제거
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());

	blockSize = rotations[0].size();
}
// game info
const int max_length = 10;
int boardH, boardW;
vector<string> board;
int covered[max_length][max_length];
int best;
// (y,x)를 왼쪽 위칸으로 해서 주어진 블록을  delta=1이면 놓고
// -1이면 없앤다
// 블록을 놓을 떄 이미 놓인 블록이나 검은 칸과 겹치면 거짓을, 아니면 참 반환
bool set(int y, int x, const vector<pair<int,int> > & block, 
int delta);
//placed 지금 까지 둔수
void search(int placed) {
	//아직 채우지 못한 빈칸 중 가장 윗줄 왼쪽 윗 칸 찾음
	int y = -1, x = -1;
	for (int i = 0; i < boardH; ++i) {
		for (int j = 0; j < boardW; ++j)
			if (covered[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		if (y != -1) break;
	}
	//base case: 게임판의 모든 칸을 처리 한 경우
	if (y == -1) {
		best = max(best, placed);
		return ;
	}
	//이 칸을 덮는다
	for (int i = 0; i < rotations.size(); ++i) {
		if (set(y,x,rotations[i], 1))
			search(placed+1);
		set(y, x, rotations[i], -1);
	}
	//이 칸을 덮지 않고 막아둔다
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
	//핵심
}
int solve() {
	best = 0;

	for (int i = 0; i < boardH; ++i)
		for (int j = 0; j < boardW; ++j)
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
	search(0);
	return best;
}