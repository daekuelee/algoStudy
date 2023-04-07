#include <iostream>
#include <algorithm>

using namespace std;
//문제 흐름
//완전탐색 -> 1000 C 10 ->memoization x
//이렇게  subproblem이 크면 유용한 방식 몇가지 존재 -> 답 구조 강제
// 양자화 되는 값은 그 수열을 묶음으로 하는 것 -> 정렬 후 묶음화
// 현재 파트의 첫 묶음 크기 정하는 문제로 치환 
//Quantize(from, parts) = min(1, n - from){ minError(from, from+size)  + Quantize(from+size, parts-1)}

const int max_n = 100;
int pSqSum[max_n+1], pSum[max_n+1];
int n;
int A[max_n+1];

void	preSortSetSub(){
	sort(A, A+n);
	pSqSum[0] = A[0] * A[0];
	pSum[0] = A[0];
	for (int i = 1; i < n; i++){
		pSum[i] = pSum[i-1] + A[i];
		pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
	}
}

int minError(int a, int b){
	int abSum = pSum[b] - (a == 0 ? 0 : pSum[a-1]);
	int abSqSum = pSqSum[b] - (a == 0 ? 0 : pSqSum[a-1]);

	int m = int(0.5 + (double)abSum / (b - a + 1));
	int ret = abSqSum - 2 * m * abSum + m * m * (b - a + 1);
	return (ret);
}
//Quantize(from, parts) = min(1, n - from){ minError(from, from+size)  + Quantize(from+size, parts-1)}

const int INF = 987654321;
const int max_parts = 10;
int cache[max_n+1][max_parts+1];
int quantize(int from, int parts){
	// base case, 양자화 완료
	if (from == n) return (0);
	// Base case -> from
	if (parts == 0) return (INF);
	
	int &ret = cache[from][parts];
	if (ret != -1) return (ret);

	ret = INF;
	for (int size = 1; size <= n - from; size++){
		ret = min(ret, minError(from, from+size-1) + quantize(from+size, parts-1));
	}
	return (ret);
}