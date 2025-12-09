#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int size, queryCount;
	cin >> size >> queryCount;

	vector<pair<int, int>> points;
	int res = 0;

	for (int i = 0; i < queryCount; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			int x, y;
			cin >> x >> y;

			points.push_back({ x, y });
		} else {
			int xl, yl, xr, yr;
			cin >> xl >> yl >> xr >> yr;

			for (auto &[x, y] : points)
				res += xl <= x && x <= xr && yl <= y && y <= yr;
		}
	}

	cout << res;
}