#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);

    long long res = 1;
    for (long long d = 2; d * d <= g; d++) {
        int power = 0;
        while (g % d == 0) {
            g /= d;
            power++;
        }
        for (int i = 0; i < power; i += 2)
            res *= d;
    }
    if (g > 1)
        res *= g;

    cout << res << "\n";
}