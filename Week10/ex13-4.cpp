#include <iostream>
#include <vector>

using namespace std;

// amout원을 연 이율 rates퍼센트로  durations월 간 한달에
// monthlyPayment로 남았을 떄 대충 잔금 ?
double balance(double amount, int duration, double rates,
double monthlyPayment) {
	double balance = amount;
	for (int i = 0; i < duration; ++i) {
		//rates
		balance *= (1.0 + (rates/12.0) / 100.0);
		balance -= monthlyPayment;
	}
	return balance;
}
//amoun원을 연 이율 rates퍼센트로  duration 동안 갚으려 면 얼마씩?
double payment(double amount, int duration, double rates) {
	//불변
	//1. lo워닜ㄱ 갚으면 d uration 개월 안에 갚을 수 업삳
	//2.hi원씩 갚으면 갚을 수 있다.
	double lo = 0, hi = amount * (1.0 + (rates / 12.0) / 100.0);
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2.0;
		if (balance(amount, duration, rates, mid) <= 0)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}