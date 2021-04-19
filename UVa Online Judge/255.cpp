#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int k, q1, q2;
	if (!(cin >> k >> q1 >> q2))
		return 0;

	if (k == q1) {
		cout << "Illegal state\n";
		return 1;
	}

	int ky = k / 8, kx = k % 8;
	int q1y = q1 / 8, q1x = q1 % 8;
	int q2y = q2 / 8, q2x = q2 % 8;

	vector<string> a(8, string(8, ' '));
	vector<int> dy = { -1, 0, 1, 0 };
	vector<int> dx = { 0, 1, 0, -1 };

	for (int d = 0; d < 4; d++) {
		for (int step = 1; step < 8; step++) {
			int ty = q1y + dy[d] * step;
			int tx = q1x + dx[d] * step;
			if (ty < 0 || ty > 7 || tx < 0 || tx > 7 || ty == ky && tx == kx)
				break;
			a[ty][tx] = 'l';
		}
	}

	if (a[q2y][q2x] != 'l') {
		cout << "Illegal move\n";
		return 1;
	}

	for (int d = 0; d < 4; d++) {
		int ty = ky + dy[d];
		int tx = kx + dx[d];
		if (ty < 0 || ty > 7 || tx < 0 || tx > 7)
			continue;
		a[ty][tx] = 'k';
	}

	if (a[q2y][q2x] == 'k') {
		cout << "Move not allowed\n";
		return 1;
	}

	for (int d = 0; d < 4; d++) {
		a[q2y][q2x] = 'q';
		for (int step = 1; step < 8; step++) {
			int ty = q2y + dy[d] * step;
			int tx = q2x + dx[d] * step;
			if (ty < 0 || ty > 7 || tx < 0 || tx > 7 || ty == ky && tx == kx)
				break;
			a[ty][tx] = 'q';
		}
	}

	for (string &row : a) {
		if (row.find('k') != -1) {
			cout << "Continue\n";
			return 1;
		}
	}

	cout << "Stop\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}