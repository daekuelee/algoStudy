#include <iostream>
#include <vector>

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v{0,1,2,3,4,5};

	vector<int> v1(v.begin(), v.begin() + v.size() / 2);
	vector<int> v2(v.begin() + v.size() / 2, v.end());
	for (int i = 0;  i < v1.size(); i++)
		cout << v1[i];
	cout << '\n';
	for (int i = 0;  i < v2.size(); i++)
		cout << v2[i];
}