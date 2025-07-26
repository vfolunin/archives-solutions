#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int eggs, int floors, int drops) {
	long long product = 1, sum = 0;
	for (int i = 1; i <= eggs && sum < floors; i++) {
		product *= drops - i + 1;
		product /= i;
		sum += product;
	}
	return sum >= floors;
}

bool solve() {
	int floors;
	cin >> floors;

	if (!floors)
		return 0;
	floors--;

	int l = 0, r = floors;
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		if (can(2, floors, m))
			r = m;
		else
			l = m;
	}

	cout << r << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}