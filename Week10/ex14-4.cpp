#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int max_n =100;
//minfactor[i] = i 의 가장 작은 소인수 (i가 소수인 경우 자기 자신)
int minFactor[max_n];
//에라토스테너스의 체를 수행하면서 소인수 분해를 위한 정보도 저장
void eratosthenes2() {
	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i <= n; ++i)
		minFactor[i] = i;
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; ++i) {
		if (minFactor[i] == i) {
			for (int j = i * i; j <= n; j += i)
				if (minFactor[j] == j)
					minFactor[j] = i;
		}
	}

}

vector<int> factor(int n) {
	vector<int> ret;

	while (n > 1) {
		ret.push_back(minFactor[n]);
		n /= minFactor[n];
	}
	return ret;
}