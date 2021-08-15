#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getPhi() {
    const int N = 1e6 + 1;

    vector<long long> phi(N);
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;

    return phi;
}

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
	long long h, w;
	cin >> h >> w;

	if (!h && !w)
		return 0;

	static vector<long long> phi = getPhi();

	double num = 0;
	for (long long y = 1; y <= h; y++) {
		long long k = w / y;
		num += k * phi[y];
		for (int x = k * y + 1; x <= w; x++)
		    num += gcd(y, x) == 1;
	}
	num = 4 * num + 4;
	
    double den = h * w * 4 + (h + w) * 2;

    cout.precision(7);
    cout << fixed << num / den << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}