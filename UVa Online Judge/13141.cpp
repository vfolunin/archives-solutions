#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getFib() {
	vector<long long> fib = { 0, 1 };
	for (int i = 2; fib.size() <= 85; i++)
		fib.push_back(fib[i - 1] + fib[i - 2]);
	return fib;
}

bool solve() {
	int n;
	cin >> n;

	if (!n)
		return 0;

	static vector<long long> fib = getFib();

	cout << fib[n] << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}