#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

bool solve(int test) {
    long long h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    h++;
    w++;

    long long p = h * w;
    long long res = p * (p - 1) * (p - 2) / 6;
    res -= h * (h - 1) * (h - 2) / 6 * w;
    res -= w * (w - 1) * (w - 2) / 6 * h;

    for (long long dy = 1; dy < h; dy++) {
        for (long long dx = 1; dx < w; dx++) {
            if (gcd(dy, dx) != 1)
                continue;
            for (long long i = 2; dy * i <= h && dx * i <= w; i++)
                res -= 2 * (i - 1) * (h - dy * i) * (w - dx * i);
        }
    }

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}