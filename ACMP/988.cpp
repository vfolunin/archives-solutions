#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

unsigned long long rec(int p, unsigned long long index) {
	unsigned long long half = (1ULL << (p - 1)) - 1;
	if (index < half)
		return rec(p - 1, index);
	else if (index == half)
		return p;
	else
		return rec(p - 1, index - half - 1);
}

void solve() {
	unsigned long long index, p;
	cin >> index >> p;
	index--;

	if (p > 63 || index < (1ULL << p) - 1)
		cout << rec(63, index) << "\n";
	else
		cout << "No solution\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve();
}