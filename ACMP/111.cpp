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

	int n;
	cin >> n;

	int res = n;

	for (int d = 1; d * d <= n; d++) {
		if (n % d)
			continue;

		if (d > 2)
			res = min(res, d - 1);
		if (n / d > 2)
			res = min(res, n / d - 1);
	}

	cout << (res != n ? res : 0);
}