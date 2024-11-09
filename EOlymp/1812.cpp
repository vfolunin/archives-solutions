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

	if (s == "#")
		return 0;

	int a = count(s.begin(), s.end(), 'A');
	int y = count(s.begin(), s.end(), 'Y');
	int n = count(s.begin(), s.end(), 'N');

	if (a * 2 >= s.size())
		cout << "need quorum\n";
	else if (y > n)
		cout << "yes\n";
	else if (y < n)
		cout << "no\n";
	else
		cout << "tie\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}