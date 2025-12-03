#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int a, b;
	if (!(cin >> a >> b))
		return 0;

	int count = a * 10 / (a + b);
	for (int i = 1; i <= 10; i++)
		cout << (i <= count ? "*" : ".");
	cout << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}