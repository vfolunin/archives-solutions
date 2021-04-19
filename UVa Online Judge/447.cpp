#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int neighbors(vector<string> &a, int y, int x) {
	static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	int res = 0;
	for (int d = 0; d < 8; d++) {
		int ty = y + dy[d], tx = x + dx[d];
		res += 0 <= ty && ty < 20 && 0 <= tx && tx < 20 && a[ty][tx] == 'O';
	}
	return res;
}

vector<string> advance(vector<string> &a) {
	vector<string> b = a;
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			int n = neighbors(a, y, x);
			if (b[y][x] == 'O' && (n <= 1 || n >= 4))
				b[y][x] = ' ';
			else if (b[y][x] == ' ' && n == 3)
				b[y][x] = 'O';
		}
	}
	return b;
}

void solve(int test) {
	int tickCount;
	cin >> tickCount;
	cin.ignore();

	vector<string> a(20, string(20, ' '));
	while (1) {
		string line;
		if (!getline(cin, line) || line.empty())
			break;

		stringstream ss(line);
		int y, x;
		ss >> y >> x;
		a[y - 1][x - 1] = 'O';
	}
	
	if (test)
		cout << "\n";
	cout << string(20, '*') << "\n";
	for (int i = 0; i < tickCount; i++) {
		for (string &row : a)
			cout << row << "\n";
		cout << string(20, '*') << "\n";
		a = advance(a);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve(i);
}