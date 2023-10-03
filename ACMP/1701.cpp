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

	int pairCount;
	cin >> pairCount;

	vector<pair<int, int>> pairs(pairCount);
	for (auto &[a, b] : pairs)
		cin >> a >> b;

	sort(pairs.begin(), pairs.end(), [](auto &lhs, auto &rhs) {
		if (lhs.first != rhs.first)
			return lhs.first < rhs.first;
		return lhs.second > rhs.second;
	});

	int res = 0;
	for (int i = 0; i + 1 < pairs.size(); i++)
		res = max(res, abs(pairs[i].second - pairs[i + 1].second));

	cout << res;
}