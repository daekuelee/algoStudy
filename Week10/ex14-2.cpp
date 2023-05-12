#include <iostream>
#include <vector>
#include <cmath>
// 주어진 정수 n을 소인수분해하는 간단한 알고리즘 
using namespace std;
vector<int> factorSimple(int n) {
	vector<int> ret;
	int sqrtn = int(sqrt(n));
	for(int div = 2; div <= sqrtn; ++div)
		while(n % div == 0) { 
			n /- div; 
			ret.push_back(div);
		}
	if (n > 1) ret.push_back(n);
	return ret;
}