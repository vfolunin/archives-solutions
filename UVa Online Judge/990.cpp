#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
	int maxWeight, w, itemCount;
	if (!(cin >> maxWeight >> w >> itemCount))
		return 0;

	vector<int> itemWeight(itemCount), itemCost(itemCount);
	for (int i = 0; i < itemCount; i++)
		cin >> itemWeight[i] >> itemCost[i];

	maxWeight /= 3 * w;
	vector<vector<int>> maxCost(itemCount + 1, vector<int>(maxWeight + 1, -1e9));
	maxCost[0][0] = 0;

	for (int items = 1; items <= itemCount; items++) {
		int curWeight = itemWeight[items - 1];
		int curCost = itemCost[items - 1];
		for (int weight = 0; weight <= maxWeight; weight++) {
			maxCost[items][weight] = maxCost[items - 1][weight];
			if (weight >= curWeight && maxCost[items - 1][weight - curWeight] != -1e9)
				maxCost[items][weight] = max(maxCost[items - 1][weight], maxCost[items - 1][weight - curWeight] + curCost);
		}
	}
	
	int bestWeight = max_element(maxCost.back().begin(), maxCost.back().end()) - maxCost.back().begin();

	if (test)
		cout << "\n";
	cout << maxCost[itemCount][bestWeight] << "\n";

	vector<int> takenItems;
	for (int items = itemCount; items; items--) {
		if (maxCost[items][bestWeight] != maxCost[items - 1][bestWeight]) {
			takenItems.push_back(items - 1);
			bestWeight -= itemWeight[items - 1];
		}
	}
	
	cout << takenItems.size() << "\n";
	for (int i = takenItems.size() - 1; i >= 0; i--)
		cout << itemWeight[takenItems[i]] << " " << itemCost[takenItems[i]] << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int i = 0; solve(i); i++);
}