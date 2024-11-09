#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	vector<int> a(4);
	for (int &value : a)
		cin >> value;

	if (count(a.begin(), a.end(), 0) == 4)
		return 0;

	int res = 0;
	while (1) {
		auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
		if (*minIt == *maxIt)
			break;

		vector<int> d(a.size());
		for (int i = 0; i < a.size(); i++)
			d[i] = abs(a[i] - a[(i + 1) % a.size()]);
		a.swap(d);

		res++;
	}

	cout << res << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}