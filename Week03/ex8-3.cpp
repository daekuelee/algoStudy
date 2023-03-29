#include <iostream>

const int max = 2500;
int cache[max][max];
bool Somecase = 0;
int baseRet = 0;
int someObscureFuncion(int a, int b){
	// base case
	if (Somecase) return (baseRet);

	int& ret = cache[a][b];
	if (ret != -1) return (ret);
	//..body

	//
	return (ret);
}

int main(void){
	memset(cache, -1, sizeof(cache));
}