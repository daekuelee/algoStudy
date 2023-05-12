#include <iostream>
#include <vector>

using namespace std;

//digits: e의 자리수 정렬
string e, digits;
int n,m;
const int max_n = 15;
//e 의 자리수로 만들 수 있는걸 모두 출력
//price : 지금까지 만든 가격
// taken 자리 사용 여부
void	generate(string price, bool taken[max_n]) {
	if (price.size() == n) {
		cout << price << '\n';
		return ;
	}

	for (int i = 0; i < n; ++i){
		if (!taken[i] && 
		(i == 0 || digits[i-1] != digits[i] || taken[i-1])){
			taken[i] = true;
			generate(price+digits[i] , taken);
			taken[i] = false;
		}
	}
}