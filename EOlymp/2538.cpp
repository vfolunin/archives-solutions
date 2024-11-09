#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	string s;
	cin >> s;

	if (s == "0")
		return 0;

	int row = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == s[i]) {
			row++;
		} else {
			cout << row << s[i - 1];
			row = 1;
		}
	}
	cout << row << s.back() << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}