#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	vector<int> pearl;
	while (1) {
		int p;
		cin >> p;

		if (!p)
			break;

		pearl.push_back(p);
	}

	if (pearl.empty())
		return 0;

	if (pearl.size() % 2 == 0) {
		cout << "NO\n";
		return 1;
	}

	sort(pearl.begin(), pearl.end());

	for (int i = 0; i + 1 < pearl.size(); i += 2) {
		if (pearl[i] != pearl[i + 1]) {
			cout << "NO\n";
			return 1;
		}
	}

	vector<int> res;
	for (int i = 0; i < pearl.size(); i += 2)
		res.push_back(pearl[i]);
	for (int i = (int)res.size() - 2; i >= 0; i--)
		res.push_back(res[i]);

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << (i + 1 < res.size() ? " " : "\n");
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}