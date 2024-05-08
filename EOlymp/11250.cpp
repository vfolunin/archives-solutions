#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long f(int a, int b, int c, int n) {
	if (n < 0)
		return 0;

	static vector<long long> memo(1001, -1);
	long long &res = memo[n];
	if (res != -1)
		return res;

	if (!n)
		return res = a;
	else
		return res = (f(a, b, c, n - 1) + b * f(a, b, c, n - 2) + c) % MOD;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b, c, n;
	cin >> a >> b >> c >> n;

	cout << f(a, b, c, n);
}