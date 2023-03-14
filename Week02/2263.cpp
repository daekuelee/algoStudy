#include <iostream>
#include <vector>

using namespace std;

// 관찰 3 -> 정렬 -> binary search vs hashing (basic find X)
int hashing[100002];
int in_ord[100002];
int	post_ord[100002];
vector<int> pre_ord;
int n;

typedef struct point{
	int st;
	int end;
}	point;
point _point(int st, int end){
	point tmp;
	tmp.st = st;
	tmp.end = end;
	return (tmp);
}
void make_pre_order(point in, point post){
	if (in.st >= in.end || post.st >= post.end){
		if (in.st == in.end)
			pre_ord.push_back(in_ord[in.st]);
		return ;
	}
	pre_ord.push_back(post_ord[post.end]);
	int idx = hashing[post_ord[post.end]];
	// cout << '\n';
	// cout << in.st << ' ' << in.end << ' ' << post.st << ' ' << post.end << '\n';
	// cout << idx<<'\n';
	// cout << '\n';
	//left_sub
	make_pre_order(_point(in.st, idx - 1), _point(post.st, post.st + idx - in.st - 1));
	// right_sub;
	make_pre_order(_point(idx + 1, in.end), _point(post.st + idx - in.st,  post.end - 1));
}
int main(void){
	ios::sync_with_stdio(0); cin.tie();

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> in_ord[i];
		hashing[in_ord[i]] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> post_ord[i];
	make_pre_order(_point(0, n - 1), _point(0, n - 1));
	for (int i = 0; i < pre_ord.size(); i++)
		cout << pre_ord[i] << ' ';
	cout << '\n';
}