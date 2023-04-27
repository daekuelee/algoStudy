#include <iostream>
#include <vector>
int n;
const int max_n = 100;
int cache[max_n+1], S[max_n], choices[max_n+1];

int lis4(int start) {
	int & ret = cache[start+1];
	if (ret != -1) return ret;

	ret = 1;
	int bestNext = -1;
	for (int next = start + 1; next < n; ++next){
		if (start == -1 || S[start] < S[next]) {
			int canDo = lis4(next) + 1;
			if (canDo > ret) {
				ret = canDo;
				bestNext = next;
			}
		}
	}
	choices[start+1] = bestNext;
	return ret;
}

void reconstruct(int start, std::vector<int>& seq){
	if (start!= -1) seq.push_back(S[start]);
	int next = choices[start+1];
	if (next != -1) reconstruct(next, seq);
}