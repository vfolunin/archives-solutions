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

	int pointCount;
	cin >> pointCount;

	set<double> angles;
	for (int i = 0; i < pointCount; i++) {
		double x, y;
		cin >> x >> y;
		angles.insert(atan2(y, x));
	}

	cout << angles.size();
}