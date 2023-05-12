#include <iostream>
#include <vector>

using namespace std;
const int max_n = 50;
int n, k, length[max_n];
double T[max_n][max_n];
vector<double> getProb2() {
	SquareMatrix W(4*n);
	//첫 3*n개의 원소는 그대로 복사해온다
	for (int i =0; i <3*n; ++i)
		W[i][i+n] = 1.0;
	//마지막 n개의 원소는 선형결합
	for (int i =0; i< n; ++i)
	//c[time][song]
	// c[time+1][i] = c[time+1-length[i]][j] * t[j][i];
		for (int j = 0; j < n; ++j)
			W[3*n+i][(4-length[j])*n+j] = T[j][i];
	SquareMatrix Wk = w.pow(k);
	vector<double> ret(n);
	for (int song = 0; song <n; ++ song)
		for (int start = 0; start < length[song]; ++start)
			ret[song] += Wk[(3-start)*n+song][3*n];
	return ret;
}