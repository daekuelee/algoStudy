#include <iostream>
#include <vector>

using namespace std;

const int max_n = 50;
int n, k, length[max_n];
double T[max_n][max_n];
vector<double> getProb1() {
	// c[time][song] = time분 후에 song번 노래가 시작할 확률
	double c[5][50];
	memset(c, 0, sizeof(c));
	c[0][0] = 1.0;
	for (int time = 1; time <= k; ++time)
		for (int song = 0; song < n; ++song) {
			double& prob = c[time % 5][song];
			prob = 0;
			for (int last = 0; last < n; ++last)
				prob += c[(time - length[last] + 5) % 5][last] *
					T[last][song];
		}
	vector<double> ret(n);
	//song 번 노래가 재생되고 있을 확률을 계산
	for (int song = 0; song < n; ++song)
		//song 번 노래가 시작했을 시간을 모두 찾아 더한다
		for (int start = k-length[song]+1; start <= k; ++start)
			ret[song] += c[start % 5][song];
	return ret;
}