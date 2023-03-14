#include <iostream>

using namespace std;

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	int origin = n;
	int quo = n / 5;
	if (n % 5 == 0){
		cout << quo << '\n';
		return (0);
	}
	n -= quo * 5;
	if (n % 3 == 0){
		cout << quo + 1 << '\n';
		return (0);
	}
	int count = 0;
	int flag = 0;
	while (n % 3 != 0){
		if (n == origin){
			flag = 1;
			break ;
		}
		quo--;
		n += 5;
		count = n / 3;
	}
	if (flag){
		cout << -1 << '\n';
		return (0);
	};
	cout << quo + count << '\n';
}