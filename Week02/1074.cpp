#include <iostream>
#include <math.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, r, c;
	int result = 0;
	cin >> n >> r >> c;
	while (n >= 1){
		if (pow(2, n - 1) > r && pow(2, n-1) > c)
			result += 0 ;
		else if (pow(2, n-1) > r && pow(2, n-1) <= c){
			result += 1 * (int)pow(2, 2 * (n - 1));
			c -= pow(2, n-1);
		}
		else if (pow(2, n-1) <= r && pow(2, n-1) > c){
			result += 2 * (int)pow(2, 2 * (n - 1));
			r -= pow(2, n-1);
		}
		else {
			result += 3 * (int)pow(2, 2 * (n - 1));
			c -= pow(2, n-1);
			r -= pow(2, n-1);
		}
		n--;
	}
	cout << result << '\n';
}