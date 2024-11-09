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

	int h, w, k;
	cin >> h >> w >> k;

	vector<vector<int>> a(h, vector<int>(w));
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			cin >> a[y][x];

	const int MOD = 1e9 + 7;
	vector<vector<int>> ways(h, vector<int>(w));
	ways[0][0] = 1;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (!ways[y][x])
				continue;

			for (int ty = y + 1; ty < h; ty++)
				for (int tx = x + 1; tx < w; tx++)
					if (a[ty][tx] != a[y][x])
						ways[ty][tx] = (ways[ty][tx] + ways[y][x]) % MOD;
		}
	}

	cout << ways[h - 1][w - 1];
}