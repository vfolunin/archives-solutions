#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	long long den;
	if (!(cin >> den))
		return 0;

	vector<pair<long long, long long>> res;
	for (long long den2 = den + 1; den2 <= 2 * den; den2++)
		if (den * den2 % (den2 - den) == 0)
			res.push_back({ den * den2 / (den2 - den), den2 });

	cout << res.size() << "\n";
	for (auto &[den1, den2] : res)
		cout << "1/" << den << " = 1/" << den1 << " + 1/" << den2 << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}