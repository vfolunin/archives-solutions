#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(vector<string> &a, int y, int x, char c) {
	return 0 <= y && y < a.size() && 0 <= x && x < a.size() && a[y][x] == c;
}

int rec(vector<string> &a, int y, int x) {
	static vector<int> dy = { -1, -1, 1, 1 };
	static vector<int> dx = { -1, 1, 1, -1 };

	int res = 0;

	for (int i = 0; i < dy.size(); i++) {
		int ty = y + dy[i], tx = x + dx[i];
		int ty2 = ty + dy[i], tx2 = tx + dx[i];

		if (check(a, ty, tx, 'B') && check(a, ty2, tx2, '.')) {
			a[y][x] = '.';
			a[ty][tx] = '.';
			a[ty2][tx2] = 'A';

			res = max(res, 1 + rec(a, ty2, tx2));

			a[y][x] = 'A';
			a[ty][tx] = 'B';
			a[ty2][tx2] = '.';
		}
	}

	return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	vector<string> a(8);
	for (string &s : a)
		cin >> s;

	int res = 0;
	for (int y = 0; y < a.size(); y++)
		for (int x = 0; x < a.size(); x++)
			if (a[y][x] == 'A')
				res = max(res, rec(a, y, x));

	cout << res;
}