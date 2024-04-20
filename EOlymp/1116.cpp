#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int n;
	if (!(cin >> n))
		return 0;

	if (n == 0) {
		cout << "10\n";
		return 1;
	}

	if (n == 1) {
		cout << "1\n";
		return 1;
	}

	vector<int> count(10);
	for (int digit = 9; digit > 1; digit--) {
		while (n % digit == 0) {
			n /= digit;
			count[digit]++;
		}
	}

	if (n > 1) {
		cout << "-1\n";
		return 1;
	}

	for (int digit = 2; digit <= 9; digit++)
		cout << string(count[digit], digit + '0');
	cout << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}