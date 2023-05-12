#include <iostream>
#include <cmath>

void infiniteBisection() {
	double lo = 123456123456.1234588623046875;
	double hi = 123456123456.1234741210937500;
	while (fabs(hi - lo) > 2e-7) 
		hi = (lo + hi) / 2.0;
	
}