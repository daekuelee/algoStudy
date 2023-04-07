#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int max_n = 100;
int S[max_n];
int cache[max_n+1];
int Selected[max_n+1];
int n;
int lis(int start){
	int &ret = cache[start+1];
	if (ret != -1) return (ret);


	ret = 1;
	int localSelect = -1;
	for (int next = start + 1; next < n; next++){
		if (start == -1 || (S[start] < S[next])){
			int tmp = lis(next)+1;
			if (ret < tmp){
				ret = tmp;
				localSelect = next;
			}
		}
	}
	Selected[start+1] = localSelect;
	return (ret);
}

void Construct(int start, vector<int> &v){
	if (start != -1) v.push_back(S[start]);
	int next = Selected[start+1];
	if (next != -1) Construct(next, v);
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; i++)
		cin>>S[i];
	cout << lis(-1)-1<<'\n';
	vector<int> answer;
	Construct(-1, answer);
	for (int i =0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	cout << '\n';
}