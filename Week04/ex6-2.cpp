#include <iostream>
#include <vector>

using namespace std;

const int max_n = 10; //뽑는 최대수 10개로 정함
int N,M;  //nCm
int Given[max_n]; // 주어진 정수들
int Comb[max_n]; // 내가 만들 조합

void	makeComb(int k, int cur){
	// 내가 이미 M개를 골랐으면 출력
	if (k == M){
		for (int i = 0; i < M; i++) cout << Comb[i] << ' ';
		cout << '\n';
		return ;
	}
	//현재 선택지 부터 N개 까지의 선택지가 주어짐
	for (int i = cur; i < N; i++){
		//현재 꺼 넣음
		Comb[k] = Given[i];
		// 다음 꺼 찾기 
		makeComb(k + 1, i + 1);
	}
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> Given[i];
	makeComb(0, 0); 
}