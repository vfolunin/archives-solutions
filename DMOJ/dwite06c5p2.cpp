#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int itemCount;
	if (!(cin >> itemCount))
		return 0;

	vector<int> items(itemCount);
	for (int &itemWeight : items)
		cin >> itemWeight;

	vector<int> canMake(1441);
	canMake[0] = 1;

	for (int itemWeight : items)
		for (int sum = canMake.size() - 1; sum >= itemWeight; sum--)
			canMake[sum] |= canMake[sum - itemWeight];

	int res = 0;
	while (!canMake[canMake.size() - 1 - res])
		res++;

	cout << res << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}