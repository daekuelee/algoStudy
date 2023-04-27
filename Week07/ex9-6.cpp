#include <iostream>

// s 지금 까지 만든 신호
// n 더 필요한 -의 개수
// m : 더 필요한 o의 개수
void generate(int n, int m, std::string s) {
	//base
	if (n == 0 && m == 0) {
		std::cout << s << '\n';
		return ;
	}
	if (n > 0) generate(n-1, m, s + "-");
	if (m > 0) generate(n, m-1, s+ "o");
}