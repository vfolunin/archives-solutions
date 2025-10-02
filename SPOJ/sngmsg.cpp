#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
	string digits, s;
	cin >> digits >> s;

	digits.insert(digits.end(), digits.rbegin(), digits.rend());

	for (int i = 0; i < s.size(); i++) {
		s[i] -= 'a';
		s[i] += 26 - (digits[i % digits.size()] - '0');
		s[i] %= 26;
		s[i] += 'a';
	}

	cout << s << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve();
}