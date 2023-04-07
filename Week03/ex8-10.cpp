#include <iostream>
#include <vector>
using namespace std;

//완전 탐색에 대해서 생각해볼것 
int lis(const vector<int> &a){
	if (a.size() == 0) return (0);

	int ret = 0;
	for (int i = 0; i < a.size(); i++){
		vector<int> b;
		for (int j = i + 1; j < a.size(); j++)
			if (a[i] < a[j])
				b.push_back(a[j]);
		ret = std::max(ret, 1 + lis(b));
	}
	return (ret);
	vector<int > a = a;
}