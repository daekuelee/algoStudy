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

int asym(int width){
	if (width % 2 == 1)
		return ((til(width) - til(width/2) + Mod) % Mod);
	
	int ret = til(width);
	ret = (ret - til(width/2) + Mod)%Mod;
	ret = (ret - til(width/2-1) + Mod) % Mod;
	return (ret);
}