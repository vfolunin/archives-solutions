#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (n < 0)
        return 0;
    n *= 2;

    for (int k = sqrt(n); k >= 1; k--) {
        if (n % k)
            continue;
        
        long long sum = n / k;
        if ((sum + 1 - k) % 2)
            continue;
        long long l = (sum + 1 - k) / 2;
        long long r = l + k - 1;

        cout << n / 2 << " = " << l << " + ... + " << r << "\n";
        break;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}