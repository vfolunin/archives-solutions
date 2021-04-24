#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	string s;
	if (!(cin >> s))
		return 0;

	int l = s.find('X'), r = s.rfind('X');
	int res = max<int>(l - 1, s.size() - 2 - r);

	int cur = 0;
	for (int i = l; i <= r; i++) {
		if (s[i] == '.') {
			cur++;
		} else {
			res = max(res, (cur - 1) / 2);
			cur = 0;
		}
	}

	cout << res << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}