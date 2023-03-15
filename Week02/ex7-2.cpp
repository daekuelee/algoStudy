#include <iostream>

using namespace std;

const int max_n = 5;
int n;

typedef struct Matrix{
	int mat[max_n][max_n];
}	Matrix;
const int Mod = 1000;
long long b;
Matrix operator*(const Matrix &a, const Matrix &b){
	Matrix	tmp;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp.mat[i][j] = 0;
			for (int k = 0; k < n; k++)
				tmp.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % Mod;
			tmp.mat[i][j] %= Mod;
		}
	}
	return (tmp);
}

Matrix solve(const Matrix &a, long long n){
	if (n == 1)
		return (a);
	if (n % 2 == 1)
		return (solve(a, n-1) * a);
	Matrix half = solve(a, n/2);
	return (half * half );
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> b;
	Matrix input;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cin >> input.mat[i][j];
	}
	Matrix result = solve(input, b);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << result.mat[i][j] % Mod << ' ';
		cout << '\n';
	}
}