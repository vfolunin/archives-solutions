#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double va, vb, y;
	cin >> va >> vb >> y;

	double l = 0, r = 1;
	for (int i = 0; i < 200; i++) {
		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;

		double t1 = hypot(m1, 1 - y) / va + hypot(1 - m1, y) / vb;
		double t2 = hypot(m2, 1 - y) / va + hypot(1 - m2, y) / vb;

		if (t1 < t2)
			r = m2;
		else
			l = m1;
	}

	cout << fixed << l;
}