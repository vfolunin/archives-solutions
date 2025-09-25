#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	vector<int> a(3);
	for (int &value : a)
		cin >> value;

	if (!a[0])
		return 0;

	vector<int> b(2);
	for (int &value : b)
		cin >> value;
	b.push_back(1);
	
	sort(a.begin(), a.end());
	do {
		if (a[0] < b[0] && a[1] < b[1])
			continue;

		if (a[0] > b[0] && a[1] > b[1]) {
			cout << "-1\n";
			return 1;
		}

		b[2] = max(b[2], a[2] + 1);
	} while (next_permutation(a.begin(), a.end()));

	set<int> values(a.begin(), a.end());
	values.insert(b.begin(), b.begin() + 2);
	while (values.count(b[2]))
		b[2]++;

	cout << (b[2] <= 52 ? b[2] : -1) << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}
