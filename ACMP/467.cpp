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

	int segmentCount;
	cin >> segmentCount;

	map<int, int> changes;
	for (int i = 0; i < segmentCount; i++) {
		int l, r;
		cin >> l >> r;

		changes[l] ^= 1;
		changes[r] ^= 1;
	}

	bool white = 1;
	int from = 0, res = 0;

	for (auto &[pos, change] : changes) {
		if (!change)
			continue;

		if (white)
			res = max(res, pos - from);

		white ^= 1;
		from = pos;
	}

	if (white)
		res = max<int>(res, 1e9 - from);

	cout << res;
}