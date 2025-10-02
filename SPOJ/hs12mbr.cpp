#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
	int shapeCount;
	cin >> shapeCount;

	int xMin = 1e9, yMin = 1e9, xMax = -1e9, yMax = -1e9;
	for (int i = 0; i < shapeCount; i++) {
		char type;
		cin >> type;

		if (type == 'p') {
			int x, y;
			cin >> x >> y;

			xMin = min(xMin, x);
			yMin = min(yMin, y);
			xMax = max(xMax, x);
			yMax = max(yMax, y);
		} else if (type == 'c') {
			int x, y, r;
			cin >> x >> y >> r;

			xMin = min(xMin, x - r);
			yMin = min(yMin, y - r);
			xMax = max(xMax, x + r);
			yMax = max(yMax, y + r);
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			xMin = min({ xMin, x1, x2 });
			yMin = min({ yMin, y1, y2 });
			xMax = max({ xMax, x1, x2 });
			yMax = max({ yMax, y1, y2 });
		}
	}

	cout << xMin << " " << yMin << " " << xMax << " " << yMax << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve();
}