#include <iostream>

using namespace std;

//초기 문자열 seed를 generation세대 진화한 결과를 출력
void curve(const string& seed, int generations) {
	if (generations == 0) {
		cout << seed << '\n';
		return ;
	}
	for (int i = 0; i < seed.size(); ++i) {
		if (seed[i] == 'X')
			curve("X+TF", generations-1);
		else if ( seed[i] == 'Y')
			curve("Fx-Y", generations-1);
		else
			cout << seed[i];
	}
}