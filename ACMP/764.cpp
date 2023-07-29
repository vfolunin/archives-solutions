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

	vector<double> angles(pointCount);
	for (double &angle : angles) {
		double x, y;
		cin >> x >> y;
		angle = atan2(y, x);
	}

	sort(angles.begin(), angles.end());

	int row = 1, maxRow = 1;
	for (int i = 1; i < angles.size(); i++) {
		if (angles[i - 1] + 1e-9 >= angles[i])
			row++;
		else
			row = 1;
		maxRow = max(maxRow, row);
	}

	cout << maxRow;
}