#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool hasDifferentDigits(long long n) {
	int u[10] = {};
	while (n) {
		if (u[n % 10])
			return 0;
		u[n % 10] = 1;
		n /= 10;
	}
	return 1;
}

void solve(int test) {
	long long n;
	cin >> n;

	if (test)
		cout << "\n";
	for (long long i = 1; i * n <= 9876543210LL; i++)
		if (hasDifferentDigits(i) && hasDifferentDigits(i * n))
			cout << i * n << " / " << i << " = " << n << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve(i);
}