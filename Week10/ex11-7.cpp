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