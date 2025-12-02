#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int groupCount;
	cin >> groupCount;

	unordered_map<string, int> count;
	for (int i = 0; i < groupCount; i++) {
		int groupSize;
		cin >> groupSize;

		for (int j = 0; j < groupSize; j++) {
			string s;
			cin >> s;

			count[s]++;
		}
	}

	vector<pair<string, int>> pairs(count.begin(), count.end());
	sort(pairs.begin(), pairs.end(), [](auto &l, auto &r) {
		if (l.second != r.second)
			return l.second > r.second;
		return l.first < r.first;
	});

	for (auto &[s, count] : pairs)
		cout << s << " " << count << "\n";
}