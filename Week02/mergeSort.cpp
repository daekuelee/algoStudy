#include <iostream>

using namespace std;

void	merge(int sum[], int left[], int right[], int n){
	int idx = 0;
	int l = 0;
	int r = 0;
	
	while (l < n/2 && r < n-n/2){
		if (left[l] < right[r]) sum[idx++] = left[l++];
		else sum[idx++] = right[r++];
	}
	while (l < n/2) sum[idx++] = left[l++];
	while (r < n-n/2) sum[idx++] = right[r++];
}

void	mergeSort(int input[], int n){
	if (n == 1) return ;

	int left[n/2];
	int right[n-n/2];
	for (int i = 0; i < n; i++){
		if (i < n / 2) left[i] = input[i];
		else right[i - n/2] = input[i];
	}
	mergeSort(left, n/2);
	mergeSort(right, n-n/2);
	merge(input, left, right,n);
}
int main(void){
	int test[10] = {-1, -130, 105, 1, 4, 5, 6, 7, 8, -260};

	mergeSort(test, 10);
	for (int i = 0; i < 10; i++)
		cout << test[i] << ' ';
}