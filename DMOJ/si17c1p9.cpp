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

	int res = 0;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (a[y][x] == 'S')
				continue;

			int num = 0, den = 0;
			for (int ty = y - 1; ty <= y + 1; ty++) {
				for (int tx = x - 1; tx <= x + 1; tx++) {
					if (0 <= ty && ty < h && 0 <= tx && tx < w && (ty != y || tx != x)) {
						num += a[ty][tx] == 'S';
						den++;
					}
				}
			}

			res += num * 2 < den;
		}
	}

	cout << res;
}