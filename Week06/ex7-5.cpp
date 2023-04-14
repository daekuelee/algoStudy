#include <iostream>

using namespace std;
//처음 생각 풀이 
// 압축을 풀까? 압축 푸는 거에 대한 난이도가 큼

const int MAX_SIZE = 2*20;
char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(std::string::iterator &it, int x, int y, int size) {
	char head = *(it++);
	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; dy++)
			for (int dx = 0; dx < size; dx++)
				decompressed[y+dy][x+dx] = head;
	}
	else {
		int half = size / 2;
		decompress(it, x, y, half);
		decompress(it, x+half, y, half);
		decompress(it, x, y+half, half);
		decompress(it, x+half, y+half, half);
	}
}