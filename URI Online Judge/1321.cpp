#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	vector<int> a(3), b(3);
	set<int> s;

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 0; i < 2; i++) {
		cin >> b[i];
		s.insert(b[i]);
	}

	if (!a[0])
		return 0;

	sort(a.begin(), a.end());
	b[2] = 1;
	bool fail = 0;

	do {
		if (a[0] < b[0] && a[1] < b[1])
			continue;
		if (a[0] > b[0] && a[1] > b[1]) {
			fail = 1;
			break;
		}
		b[2] = max(b[2], a[2] + 1);
	} while (next_permutation(a.begin(), a.end()));

	while (s.count(b[2]))
		b[2]++;

	if (fail || b[2] > 52)
		cout << "-1\n";
	else
		cout << b[2] << "\n";
	return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	while (solve());
}