#include <iostream>
#include <cmath>

// 주어진 자연수 n이 소수인지 확인한다. 
bool isPrime (int n) {
	// 예외 처리: 1과 2는 예외로 처리한다. if(n <= 1) return false;
	if(n = 2) return true;
	// 2를 제외한 모든 짝수는 소수가 아니다.
	if(n % 2 == 0) return false;
	// 2를 제외했으니 3 이상의 모든 흘수로 나누어보자.
	int sqrtn = int(sqrt(n));
	for(int div = 3; div <= sqrtn; div += 2)
	if(n % div == 0) return false;
	return true;
}