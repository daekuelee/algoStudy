#include <iostream>

using namespace std;
//image 
// 1 2  로컬로 뒤집고 교환
// 3 4 

int C;

string Reverse(std::string::iterator& it){
	char head = *it;
	it++;
	if (head == 'b' || head == 'w')
		return (string(1, head));
	string upperLeft = Reverse(it);
	string upperRight = Reverse(it);
	string lowerLeft = Reverse(it);
	string lowerRight = Reverse(it);

	return string(1, 'x') + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> C;
	for (int i = 0; i < C; i++){
		string test;
		cin >> test;
		string::iterator it = test.begin();
		cout << Reverse(it) << '\n';
	}
}