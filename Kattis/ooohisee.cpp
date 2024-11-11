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

	vector<string> a(h);
	for (string &s : a)
		cin >> s;

	vector<pair<int, int>> cells;
	for (int y = 1; y + 1 < h; y++) {
		for (int x = 1; x + 1 < w; x++) {
			if (a[y][x] != '0')
				continue;

			int count = 0;
			for (int ty = y - 1; ty <= y + 1; ty++)
				for (int tx = x - 1; tx <= x + 1; tx++)
					count += a[ty][tx] == 'O';

			if (count == 8)
				cells.push_back({ y, x });
		}
	}

	if (cells.size() == 1) {
		cout << cells[0].first + 1 << " " << cells[0].second + 1;
	} else {
		cout << "Oh no!";
		if (cells.size() > 1)
			cout << " " << cells.size() << " locations";
	}
}