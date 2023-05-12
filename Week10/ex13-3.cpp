#include <iostream>
#include <vector>

using namespace std;

vector<double> differentiate(const vector<double>& poly);

vector<double> solveNaive(const vector<double>& poly);

double evaluate(const vector<double>& poly, double x0);
const double L = 25;

vector<double> solve(const vector<double>& poly) {
	int n = poly.size() - 1;

	if (n <=  2) return solveNaive(poly);

	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);

	sols.insert(sols.begin(), -L-1);
	sols.insert(sols.end(), L+1);
	vector<double> ret;
	for (int i = 0; i + 1 < sols.size(); ++i) {
		double x1 = sols[i], x2 = sols[i+1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);

		//f(x1)과 f(x2)의 부호가 같은 경우 답은 없다
		if (y1 * y2 > 0) continue ;
		//불변 조건 :f(x1) <= 0 < f(x2)
		if (y1 > y2) {swap(y1,y2); swap(x1,x2)};

		for (int it = 0; it < 100; ++it) {
			double mx = (x1+x2) / 2;
			double my = evaluate(poly, mx);
			if (y1 * my > 0) {
				y1 = my;
				x1 = mx;
			}
			else {
				y2 = my;
				x2 = mx;
			}
			ret.push_back((x1+x2)/2);
		}
		sort(ret.begin(), ret.end());
		return ret;
	}
}