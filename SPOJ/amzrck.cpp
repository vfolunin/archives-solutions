#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
	int size;
	cin >> size;

	vector<int> ways(size + 1, 1);
	for (int i = 1; i < ways.size(); i++)
		for (int j = 1; j + 1 < i; j++)
			ways[i] += ways[j];

	int res = 0;
	for (int ways : ways)
		res += ways;

	cout << res << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve();
}