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

	int iterationCount = 0;
	while (1) {
		string s = to_string(n);

		sort(s.rbegin(), s.rend());
		s += string(4 - s.size(), '0');
		int a = stoi(s);

		reverse(s.begin(), s.end());
		int b = stoi(s);

		if (n == a - b)
			break;

		n = a - b;
		iterationCount++;
	}

	cout << n << "\n" << iterationCount;
}