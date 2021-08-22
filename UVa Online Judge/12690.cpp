#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sumOdd(long long n) {
    return n * n;
}

long long sumOddSquares(long long n) {
    return n * (4 * n * n - 1) / 3;
}

long long sumOddCubes(long long n) {
    return n * n * (2 * n * n - 1);
}

bool solve() {
    long long h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    h++;
    w++;
    long long m = min(h, w) / 2;

    long long res = sumOddCubes(m);
    res -= (h + w) * sumOddSquares(m);
    res += (h * w) * sumOdd(m);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}