#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
// A[]: 양자화해야할 수열, 정렬한 상태
// pSum[] : A의 부분합 저장,  PSum[i]는 A[0~i]의 합
// PSqSum[]: A의 제곱의 부분합을 저장

int n;
const int max_n = 100;
int A[max_n+1], pSum[max_n+1], pSqSum[max_n+1];

void	preSortSetSubsum() {
	sort(A, A+n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for  (int i = 1; i < n; i++){
		pSum[i] = pSum[i-1] + A[i];
		pSqSum[i] = pSqSum[i-1] + A[i]*A[i];
	}
}

int minError(int lo, int hi){
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
	int sQsum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);

	int m = int(0.5 + (double)sum / (hi - lo + 1)); //반올림
	//sum(A[i]-m) ^2 
	int ret = sQsum - 2 * m * sum + m * m * (hi -lo+1);
	return (ret);
}
const int max_n = 100;
const int max_s = 10;
int cache[max_n+1][max_s+1];

int quantize(int from, int parts){
	//기저사례: 모든 숫자를 다 양자화
	if (from == n) return (0);
	// 기저 사례: 숫자는 아직 남았는데 더 묶을 수 없을 때 아주 큰값반환 
	if (parts == 0) return (INF);

	int &ret = cache[from][parts];
	if(ret != -1) return (ret);
	ret = INF;

	for (int partSize = 1; from + partSize <= n; ++partSize){
		ret = min(ret, minError(from, from + partSize - 1) + 
					quantize(from+ partSize, parts - 1));
	}
	return (ret);
}