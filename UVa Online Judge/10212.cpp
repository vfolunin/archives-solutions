#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int n, m;
	if (!(cin >> n >> m))
		return 0;

	static long long MOD = 1e10;
	long long res = 1;
	for (long long i = n; i > n - m; i--) {
		res *= i;
		while (res % 10 == 0)
			res /= 10;
		res %= MOD;
	}

	cout << res % 10 << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}