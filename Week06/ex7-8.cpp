#include <iostream>
#include <vector>

using namespace std;

const int max_n = 20000;
int h[max_n+1];

int solve(int left, int right){
	// base_case  size = 1;
	if (left == right) return (h[left]);
	// base_case max(left, right);
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid+1, right));
	// 걸치는 거 찾기
	//걸치는거 시작 두개
	int lo = mid;
	int hi = mid+1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);
	while (lo > left || hi < right) {
		if (hi < right && (h[lo-1] < h[hi+1] || lo == left)) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi -lo +1));
	}
	return (ret);
}

int C;

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> C;
	for (int i = 0; i < C; i++){
		int n;
		cin>> n;
		for (int i = 0; i < n; i++)
			cin >> h[i];
		cout << solve(0, n-1) << '\n';
	}
}