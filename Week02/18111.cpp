#include <iostream>
#include <vector>

using namespace std;

int input[500][500];
int result[257];
int origin_inven;
int n,m;

void simul(int height){
	int re = 0;
	int flag = 0;
	int inven = origin_inven;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (input[i][j] > height){
				re += (input[i][j] - height) * 2;
				inven += (input[i][j] - height);
			}
			else {
				re += (height - input[i][j]);
				inven -= (height - input[i][j]);
			}
						
		}
	}
	if (inven < 0)
		result[height] = -1;
	else
		result[height] = re;
}
vector<int> ans;
int main(void){
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 257; i++) result[i] = -1;
	cin >> n;
	cin >> m;
	cin >> origin_inven;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> input[i][j]; 
		}
	}
	for (int i = 0; i < 257; i++) simul(i);
	int small = INT32_MAX;
	for (int i = 0; i < 257; i++) {
		if (result[i] != -1 && small > result[i])
			small = result[i];
	}
	for (int i = 0; i< 257; i++){
		if (small == result[i])
			ans.push_back(i);
	}
	cout << small << ' ' << ans[ans.size() - 1] << '\n';
}