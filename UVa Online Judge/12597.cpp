#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    unsigned long long mantissaBits, exponentBits;
    cin >> mantissaBits >> exponentBits;

    if (!mantissaBits && !exponentBits)
        return 0;

	mantissaBits++;
	unsigned long long maxExponent = (1ULL << exponentBits) - 1;
	unsigned long long maxMantissa = (1ULL << mantissaBits) - 1;

	if (maxExponent < mantissaBits) {
		cout << (1ULL << maxExponent) - 1 << "\n";
	} else {
		unsigned long long res = maxMantissa;
		res += (1ULL << (mantissaBits - 1)) * (maxExponent - mantissaBits);
		cout << res << "\n";
	}
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}