#include <iostream>
#include <vector>

using namespace std;

//도경이가 할 생각이 있는 최대 게임수
long long L = 200000000;
// b 게임 중  a 게임 승리해씅ㄹ 떄 승률
int ratios(long long b, long long a) {
	return (a * 100) / b;
}
//최소 몇 연승해야 승률이 올라갈까?
int neededGames(long long games, long long won) {
	//불가능 걸러냄
	if (ratios(games, won) == ratios(games + L, won + L))
		return -1;
	long long lo = 0, hi = L;
	//반복문 불변식:
	//1 lo이기면 승률 안변함
	//2 hi 이기면 승률 변함
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if (ratios(games, won) == ratios(games + mid, won + mid))
			lo = mid;
		else
			hi = mid;
	}
	return hi; 
}