#include <iostream>
#include <utility>

// 코드에 문제 있음 나중에 수정
using namespace std;

const int Max = 20;
const int White = 0;
const int black = 1;
int	map[Max][Max];
int countWhite;
int finish;
int T,H,W;

typedef pair<int,int > dxDy;
//[Type][2 point(x,y)]
//더 많은 방법이 존재하지만 가장 맨 왼쪽맨 위를 중심으로 덮는 방법으로 제한.
const dxDy coverType[4][3] = {
	{make_pair(0, 0), make_pair(1, 0), make_pair(0, 1)},
	{make_pair(0, 0), make_pair(1, 0), make_pair(1, 1)}, 
	{make_pair(0, 0), make_pair(0, 1), make_pair(1, 1)}, 
	{make_pair(0, 0), make_pair(-1, 1), make_pair(0, 1)}  
};

void	ioRead(void){
		for (int y = 0; y < H; y++){
			for (int x = 0; x < W; x++){
				char tmp;
				cin >> tmp;
				if (tmp == '\n')
					cin >> tmp;
				if (tmp == '#')
					map[y][x] = black;
				else {
				 	map[y][x] = White;
					countWhite++;
				}
			}
		}
}

bool coverThisStep(int x, int y, int delta, int type){
	bool ok = true;
	for (int i = 0; i < 3; i++){
		int ny = y + coverType[type][i].second;
		int nx = x + coverType[type][i].first;
		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			ok = false;
		else if ((map[ny][nx] += delta) > 1)
			ok = false;
	}
	return (ok);
}
int countCoverType(void){
	int	startX = -1;
	int startY = -1;
	for (int y = 0; y < H; y++){
		for (int x = 0; x < W; x++){
			if (map[y][x] == White){
				startX = x;
				startY = y;
				break;
			}
		}
		if (startX != -1 && startY != -1) break;
	}
	if (startX == -1 && startY == -1) {
		return (1);
	}

	int ret = 0;
	for (int Type = 0; Type < 4; Type++){
		if (coverThisStep(startX, startY, 1, Type)){
			ret += countCoverType();
		}
		coverThisStep(startX, startY, -1, Type);
	}
	return (ret);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> H >> W;
		countWhite = 0;
		ioRead();

		for (int y = 0; y < H; y++){
			for (int x = 0; x<W; x++)
				cout << map[y][x];
			cout << '\n';
		}
		if (countWhite % 3 != 0) {
			cout << 0 << '\n';
			continue ;
		}
		finish = countWhite / 3;
		cout << countCoverType() << '\n';
	}
}