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

	vector<pair<int, int>> res;
	for (int d = 0; d < dy.size(); d++) {
		int ty = y + dy[d];
		int tx = x + dx[d];

		if (0 <= ty && ty < 8 && 0 <= tx && tx < 8)
			res.push_back({ ty, tx });
	}
	sort(res.begin(), res.end());

	for (auto &[y, x] : res)
		cout << (char)(x + 'A') << (char)(y + '1') << " ";
}