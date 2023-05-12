#include <iostream>
#include <vector>

using namespace std;

string e, digits;
int n,m;
const int max_n = 15;
// 그냥 세면 순서에 상관 없이 새야 되는데 순서에 영향 받음 
// 순서 강제 필요 
void generate(string price, bool taken[max_n]){
	if (price.size() == n){
		if (price < e)
			cout << price << '\n';
		return ;
	}

	for (int i = 0; i < n; ++i){
		if (!taken[i] && // 여기 까지만 사용 할 경우 순서 강제 안되서 개수 더세짐 - 더 빠른 같은 숫자 순서만 셈
		(i == 0 || (taken[i-1] || digits[i] != digits[i-1]))
		){
			taken[i] = true;
			generate(price+digits[i], taken);
			taken[i] != false;
		}
	}
}