#include <iostream>
#include <vector>

using namespace std;

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

// a+= b*(10^k)구현
void addTo(vector<int>& a, const vector<int>& b, int k);

void subFrom(vector<int>& a, const vector<int>& b);

vector<int> karatsuba(const vector<int>&a, const vector<int>& b){
	int an = a.size(), bn = b.size();
	//a가 b보다 짧을경우 둘을 바꾼다
	if (an < bn) return karatsuba(b,a);
	// 기저 사례 a나 b가 비어있는 경우
	if (an == 0 || bn == 0) return vector<int>();
	//기저사례 :a가 비교적 짧은 경우 O(n^2)곰셈 이용
	if (an <= 50) return multiply(a,b);
	int half = an / 2;
	//분리

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));

	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	//z2 = a1*b1;
	vector<int> z2 = karatsuba(a1, b1);
	//z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half+half);
	return (ret);
}