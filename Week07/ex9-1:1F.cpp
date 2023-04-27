#include <iostream>
#include <vector>

using namespace std;

const int N_FACTORIAL = 100000;
int cache[N_FACTORIAL];
//N!개의 입력 중 key가 몇번째에 해당하는 지 반환
int mapFunc(const vector<int>& key);
int f(const vector<int>& key) {
	//base case
	//..
	int & ret = cache[mapFunc(key)];
	if (ret!=-1) return (ret);
	//..
	return ret;
}