#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorCount(int n) {
	int count = 0;

	for (long long d = 1; d * d <= n; d++) {
		if (n % d == 0) {
			count++;
			count += d * d != n;
		}
	}

	return count;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	long long n;
	cin >> n;

	if (n < 5e6) {
		for (long long i = n; i <= 1.01 * n; i++) {
			if (getDivisorCount(i) >= 100) {
				cout << i;
				return 0;
			}
		}

		cout << -1;
	} else {
		long long higlyComposite = 45360;
		long long k = (n + higlyComposite - 1) / higlyComposite;

		cout << higlyComposite * k;
	}
}