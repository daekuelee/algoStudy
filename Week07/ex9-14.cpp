#include <iostream>
#include <vector>

using namespace std;

//factorials[i] = i!;
int factorials[12];

//X가 [0....n-1]순열 -> 사전순 번호 반환 (0시작)
int getIndex(const vector<int>& X) {
	int ret = 0;
	for (int i = 0; i < X.size(); ++i) {
		int less = 0;
		//X[i+1..]중 X[i]보다 작은 수를 센다. 
		for (int j = i +1; j < X.size(); ++j)
			if (X[j] < X[i])
				++less;
		ret += factorials[X.size() - i - 1] * less;
	}
	return (ret);
}