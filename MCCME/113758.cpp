#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sqrtGe(long long n) {
	long long res = max(0.0, sqrt(n));
	while (res * res < n)
		res++;
	return res;
}

long long sqrtLe(long long n) {
	long long res = sqrt(n) + 1;
	while (res * res > n)
		res--;
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long a, b, k;
	cin >> a >> b >> k;

	long long xl = sqrtGe(a);
	long long xr = sqrtLe(b);
	long long res = 0;

	for (long long y = 1; y <= 1e6; y++) {
		if (y * y * y < a || b < y * y * y)
			continue;

		long long l = sqrtGe(max(0LL, y * y * y - k));
		long long r = sqrtLe(y * y * y + k);

		l = max(l, xl);
		r = min(r, xr);

		if (l <= r)
			res += r - l + 1;
	}

	cout << res;
}