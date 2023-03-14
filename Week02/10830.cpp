#include <iostream>
#include <vector>

const int MAX = 5;
const int Mod = 1000;
using namespace std;
typedef struct matrix{
	int mat[MAX][MAX];
}Matrix;
int n;
long long b;
// Matrix init(int size){
// 	Matrix tmp;
// 	tmp.size = size;
// 	for (int i = 0; i < size; i++){
// 		for (int j = 0; j < size; j++)
// 			tmp.mat[i][j] = 0;
// 	}
// 	return (tmp);
// }
Matrix operator*(const Matrix &a, const Matrix &b){
	Matrix tmp;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp.mat[i][j] = 0;
			for (int k = 0; k < n; k++){
				tmp.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % Mod;
			}
			tmp.mat[i][j] %= Mod;
		}
	}
	return (tmp);
}

Matrix solve(const Matrix &a, long long size){
	if (size == 1)
		return (a);
	if (size % 2 == 1)
		return (solve(a, size - 1) * a);
	Matrix half = solve(a, size / 2);
	return (half * half);
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