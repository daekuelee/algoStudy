#include <iostream>

using namespace std;

// 1 + 2+ ... n /2 + n/2 +1 + n/2+2 +.... n/2+n/2
// f(n/2) + n/2 * n/2 + f(n/2)
// (n ^2) / 4 + 2* (n/2)

int	fastSum(int n){
	if (n==1) return (1);
	if (n % 2 == 1) return fastSum(n-1) + n;
	else return 2 * fastSum(n/2) + n * n /4;
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	cout << fastSum(n) << '\n';
}