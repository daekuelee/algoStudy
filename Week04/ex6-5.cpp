#include <iostream>

int n;
bool areFriends[10][10];

//사전  -순서강제
// 백트래킹 
// 사전
int countParings(bool taken[10]){
	int firstFree = -1;

	// 가장 빠른 번호의 학생 찾기
	for (int i = 0; i < n; ++i){
		if (!taken[i]) {
			firstFree = i;
			break ;
		}
	}
	
	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFre + 1; pairWith < n; ++pairWith){
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return (ret);
}