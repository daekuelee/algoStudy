#include <iostream>

const int Mod = 1000000007;
const int max_n = 100;
int cache[max_n+1];

int til(int width){
	if (width <= 1) return 1;

	int &ret = cache[width];
	if (ret != -1) return (ret);
	
	return (ret = til(width-2) + til(width-1) % Mod);
}

int cache2[max_n+1];
int asym2(int width){
	//base Case
	if (width <= 2)
		return (0);
	int &ret = cache2[width];
	if (ret != -1) return (ret);
	ret = asym2(width-2) % Mod;
	ret = (ret + asym2(width-4))%Mod;
	ret = (ret + til(width-3))%Mod;
	ret = (ret + til(width-3))%Mod;
	return (ret);
}