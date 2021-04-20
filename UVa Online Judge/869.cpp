#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> getReachable() {
	int edgeCount;
	cin >> edgeCount;

	vector<vector<int>> reachable(26, vector<int>(26));
	for (int i = 0; i < edgeCount; i++) {
		char a, b;
		cin >> a >> b;
		reachable[a - 'A'][b - 'A'] = 1;
		reachable[b - 'A'][a - 'A'] = 1;
	}

	for (int v = 0; v < 26; v++)
		for (int a = 0; a < 26; a++)
			for (int b = 0; b < 26; b++)
				if (reachable[a][v] && reachable[v][b])
					reachable[a][b] = 1;

	return reachable;
}

void solve(int test) {
	if (test)
		cout << "\n";
	cout << (getReachable() == getReachable() ? "YES\n" : "NO\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve(i);
}