#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int dp[501][501];
typedef pair<int,int> P;
vector<P> arr;
int N;
int INF = 2147483647;
 
int func(int begin, int end) {
    int& ret = dp[begin][end];
    if (ret != 0)return ret;
    if (begin == end)
        return 0;
    ret = INF;
    for (int i = begin; i < end; i++) {
        ret = min(ret, func(begin, i) + func(i + 1, end) + arr[begin].first * arr[i].second * arr[end].second);
    }
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int a, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        arr.push_back(P(a,b));
    }
    cout << func(0,N-1) << '\n';
}