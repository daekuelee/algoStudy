#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, capacity;
const int max_n = 100;
const int max_c = 1000;
int volume[max_n], need[max_n];
int cache[max_c+1][max_n];
string name[max_n];

int pack(int cap, int item) {
	if (item == n) return 0;
	int &ret = cache[cap][item];
	if (ret != -1) return (ret);

	ret = pack(cap, item+1);
	if (cap >= volume[item])
		ret = max(ret, need[item]+ pack(cap - volume[item], item+1));
	return (ret);
}

void reconstruct(int cap, int item, vector<string>& picked) {
	if (item == n) return ;
	if (pack(cap, item) == pack(cap, item + 1)) 
		reconstruct(cap, item+1, picked);
	else {
		picked.push_back(name[item]);
		reconstruct(cap - volume[item], item+1, picked);
	}
}