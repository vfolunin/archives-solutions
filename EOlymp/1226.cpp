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

	map<pair<int, int>, int> count;
	for (int i = 0; i < size; i++) {
		int a, b;
		cin >> a >> b;
		count[{ a, b }]++;
	}

	for (auto &[p, k] : count) {
		auto it = count.find({ p.second, p.first });
		if (it == count.end() || it->second != k) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve();
}