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

	int before, after;
	cin >> before >> after;

	if (after == 1) {
		cout << before;
	} else {
		int res = 0;
		for (int gap = 0; after + (after - 1) * gap <= before; gap++)
			res += before - (after + (after - 1) * gap) + 1;
		cout << res;
	}
}