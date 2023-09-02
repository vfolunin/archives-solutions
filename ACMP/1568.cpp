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

	int resourceCount, unitCount;
	cin >> resourceCount >> unitCount;

	vector<int> resources(resourceCount);
	for (int &value : resources)
		cin >> value;

	for (int i = 0; i < unitCount; i++) {
		bool can = 1;
		for (int j = 0; j < resourceCount; j++) {
			int value;
			cin >> value;

			can &= resources[j] >= value;
		}

		cout << can << " ";
	}
}