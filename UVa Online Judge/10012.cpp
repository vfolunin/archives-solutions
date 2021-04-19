#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
	int circleCount;
	cin >> circleCount;

	vector<double> radius(circleCount);
	for (double &r : radius)
		cin >> r;

	double res = 1e9;

	sort(radius.begin(), radius.end());
	do {
		vector<double> x(circleCount);
		x[0] = radius[0];

		for (int i = 1; i < circleCount; i++) {
			for (int j = 0; j < i; j++) {
				double dy = radius[i] - radius[j];
				double dr = radius[i] + radius[j];
				double dx = sqrt(dr * dr - dy * dy);
				double curX = max(x[j] + dx, radius[i]);
				x[i] = max(x[i], curX);
			}
		}

		double curRes = 0;
		for (int i = 0; i < circleCount; i++)
			curRes = max(curRes, x[i] + radius[i]);

		res = min(res, curRes);
	} while (next_permutation(radius.begin(), radius.end()));

	cout.precision(3);
	cout << fixed << res << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve();
}