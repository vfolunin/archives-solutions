#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int cubeCount;
	cin >> cubeCount;

	if (!cubeCount)
		return 0;

	int zl = -1e9, zr = 1e9;
	int yl = -1e9, yr = 1e9;
	int xl = -1e9, xr = 1e9;

	for (int i = 0; i < cubeCount; i++) {
		int cxl, cyl, czl, csize;
		cin >> cxl >> cyl >> czl >> csize;

		xl = max(xl, cxl);
		xr = min(xr, cxl + csize);
		yl = max(yl, cyl);
		yr = min(yr, cyl + csize);
		zl = max(zl, czl);
		zr = min(zr, czl + csize);
	}

	cout << max(0, xr - xl) * max(0, yr - yl) * max(0, zr - zl) << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}