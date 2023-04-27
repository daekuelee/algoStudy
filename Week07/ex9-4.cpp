#include <iostream>

using namespace std;
int n,m;
//분류기가 반환한 문장. 단어, 번호로 변환
const int max_n = 100;
const int max_m = 500;
int R[max_n];
// T[i][j] = i 단어뒤 j 나올 확률 -> log
double T[max_m+1][max_m+1];
// M[i][j] -> I 단어가 j로 분류될 확률
double M[max_m+1][max_m+1];
int choice[max_n+2][max_m+2];
double cache[max_n+2][max_m+2]; // 1

//Q[sement]이후를 채워서 얻을 수 있는 최대  g()곱의 로그 값 반환
// Q[sement-1] == previousMatch
double recognize(int segment, int previousMatch) {
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;

	ret = 1e200;
	int & choose = choice[segment][previousMatch];
	// R[segment]에 대응 되는 단어를 찾는다
	for (int thisMatch = 0; thisMatch < m; ++thisMatch) {
		// g(thisMatch) = T(previousMatch, thisMatch) *
		// M(this Match, R[segment])
		double canDo = T[previousMatch][thisMatch] +
		M[thisMatch][R[segment]] + recognize(segment+1, thisMatch);
		if (ret < canDo) {
			ret = canDo;
			choose = thisMatch;
		}
	}
	return ret;
}

string corpus[max_m+1];
string reconstruct(int segment, int previousmatch) {
	int choose = choice[segment][previousmatch];
	string ret = corpus[choose];
	if (segment < n - 1)
		ret = ret + " " + reconstruct(segment+1, choose);
	return (ret);
}