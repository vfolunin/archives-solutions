#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	double a, b, h;
	if (!(cin >> a >> b >> h))
		return 0;

	double l = 0, r = min(a, b);
	for (int i = 0; i < 200; i++) {
		double m = (l + r) / 2;
		double ah = sqrt(a * a - m * m);
		double bh = sqrt(b * b - m * m);
		if (1 / ah + 1 / bh < 1 / h)
			l = m;
		else
			r = m;
	}

	cout.precision(3);
	cout << fixed << l << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}