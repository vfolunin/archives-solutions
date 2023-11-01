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

	string a, b;
	cin >> a >> b;

	vector<pair<int, int>> res;
	for (int l = 0; l < a.size(); l++) {
		if (a[l] == b[l])
			continue;

		int r = a.find(b[l], l);
		reverse(a.begin() + l, a.begin() + r + 1);
		res.push_back({ l, r });
	}

	cout << res.size() << "\n";
	for (auto &[l, r] : res)
		cout << l + 1 << " " << r + 1 << "\n";
}