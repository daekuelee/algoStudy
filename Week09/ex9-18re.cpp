#include <iostream>

using namespace std;

const int max_k = 15;
int k;
string Word[max_k];
int cache[max_k][1<<max_k], overlap[max_k][max_k];

int restore(int last, int used) {
	//base
	if (used == (1<<k)-1) return (0);

	int &ret = cache[last][used];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = 0; next < k; next++){
		if ((1<<next) & used == 0) {
			int cand = overlap[last][next] +
				restore(next, used + (1<<next));
			ret = max(ret, cand);
		}
	}
	return ret;
}