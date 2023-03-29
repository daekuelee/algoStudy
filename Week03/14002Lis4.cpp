#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int max_n = 1000;
int cache[max_n + 1];
int Select[max_n + 1];
int n;
int input[max_n];
//basic
int lis(int start){
	int &ret = cache[start + 1];
	if (ret != -1) return (ret);

	int bestSelect = -1;
	for (int next = start + 1; next < n; next++){
		if (start == -1 || (input[start] < input[next])){
			int tmp = lis(next) + 1;
			if (ret < tmp){
				ret = tmp;
				bestSelect = next;
			}
		}
	}
	Select[start + 1] = bestSelect;
	return (ret);
}

void reLis(int start, vector<int> &s){
	if (start != -1)	s.push_back(input[start]);
	int next = Select[start + 1];
	if (next != -1) reLis(next, s);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	cout << lis(-1) - 1 << '\n';
	vector<int> answer;
	reLis(-1, answer);
	for (int i =0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	cout << '\n';
}