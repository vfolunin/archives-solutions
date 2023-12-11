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

	int h, w;
	cin >> h >> w;

	vector<vector<int>> a(h, vector<int>(w));
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			cin >> a[y][x];

	vector<vector<int>> cost = a;
	vector<vector<pair<pair<int, int>, char>>> from(h, vector<pair<pair<int, int>, char>>(w));

	for (int y = h - 1; y >= 0; y--) {
		for (int x = 0; x < w; x++) {
			if (y == h - 1 && !x) {
				continue;
			} else if (y == h - 1 || x && cost[y + 1][x] < cost[y][x - 1]) {
				cost[y][x] = a[y][x] + cost[y][x - 1];
				from[y][x] = { { y, x - 1 }, 'R' };
			} else {
				cost[y][x] = a[y][x] + cost[y + 1][x];
				from[y][x] = { { y + 1, x }, 'F' };
			}
		}
	}

	string path;
	for (int y = 0, x = w - 1; y != h - 1 || x; ) {
		auto &[py, px] = from[y][x].first;
		path += from[y][x].second;
		y = py;
		x = px;
	}
	reverse(path.begin(), path.end());

	cout << path;
}