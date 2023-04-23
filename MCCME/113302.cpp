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

	char x, y;
	cin >> x >> y;
	x -= 'A';
	y -= '1';

	vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
	vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

	set<pair<int, int>> res;
	for (int d = 0; d < dy.size(); d++) {
		int ty = y + dy[d];
		int tx = x + dx[d];

		if (ty < 0 || ty > 7 || tx < 0 || tx > 7)
			continue;

		for (int d2 = 0; d2 < dy.size(); d2++) {
			int t2y = ty + dy[d2];
			int t2x = tx + dx[d2];

			if (t2y < 0 || t2y > 7 || t2x < 0 || t2x > 7)
				continue;

			res.insert({ t2y, t2x });
		}
	}

	for (auto &[y, x] : res)
		cout << (char)(x + 'A') << (char)(y + '1') << " ";
}