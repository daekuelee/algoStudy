#include <iostream>
#include <vector>
using namespace std;

// int 배열로 저장, 현재 뒷 자리수 부터 저장 

void	normalize(vector<int> &c){
	c.push_back(0);

	for (int i = 0; i + 1 < c.size(); i++){
		if (c[i] < 0) {
			int borrow = (abs(c[i]) + 9) / 10;
			c[i + 1] -= borrow;
			c[i] += borrow * 10;
		}
		else {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
}

vector<int> multiply(const vector<int> &a, const vector<int> &b){
	vector<int> c(a.size() + b.size(), 0);

	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < b.size(); j++){
			c[i+j] += a[i] * b[j];
		}
	}
	normalize(c);
	return (c);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	const int a[11] = {2,1,3,6,4,7,4,8,9,1,0};
	vector<int> x;
	vector<int> y;
	for (int i = 10; i >= 0; i--){
		x.push_back(a[i]);
		y.push_back(a[i]);
	}
	for (int i = 0; i < x.size(); i++)
		cout << x[i];
	cout << '\n';
	vector<int> mul = multiply(x, y);
	for (int i = mul.size() - 1; i > 0; i--)
		cout << mul[i];
	cout << '\n';
}