#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcdex(long long a, long long b, long long &x, long long &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	long long x1, y1, d = gcdex(b, a % b, x1, y1);
	x = y1;
	y = x1 - a / b * y1;
	return d;
}

bool solve() {
	long long n, a, b, costA, costB;
	if (!(cin >> n >> costA >> a >> costB >> b))
		return 0;

	long long x, y, d = gcdex(a, b, x, y);
	if (n % d) {
		cout << "failed\n";
		return 1;
	}

	x *= n / d;
	y *= n / d;
	a /= d;
	b /= d;

	if (x < 0) {
		long long k = (-x + b - 1) / b;
		x += k * b;
		y -= k * a;
	}
	if (y < 0) {
		long long k = (-y + a - 1) / a;
		x -= k * b;
		y += k * a;
	}
	if (x < 0) {
		cout << "failed\n";
		return 1;
	}

	long long bestX = x, bestY = y;

	long long k = x / b;
	x -= k * b;
	y += k * a;
	if (x * costA + y * costB < bestX * costA + bestY * costB) {
		bestX = x;
		bestY = y;
	}

	k = y / a;
	x += k * b;
	y -= k * a;
	if (x * costA + y * costB < bestX * costA + bestY * costB) {
		bestX = x;
		bestY = y;
	}

	cout << bestX << " " << bestY << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}