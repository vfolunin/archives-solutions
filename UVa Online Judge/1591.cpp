#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long f(long long x, long long a, long long b) {
    return (x + (x << a)) >> b;
}

bool solve() {
    long long n, sizeA, sizeB;
    if (!(cin >> n >> sizeA >> sizeB))
        return 0;

    long long bestSize = -1, bestA, bestB;
    for (int a = 0; a <= 31; a++) {
        for (int b = 0; b <= 31; b++) {
            if (f(sizeA, a, b) >= sizeB) {
                long long size = f(sizeA * (n - 1), a, b) + sizeB;
                if (bestSize == -1 || bestSize > size) {
                    bestSize = size;
                    bestA = a;
                    bestB = b;
                }
            }
        }
    }

    cout << bestSize << " " << bestA << " " << bestB << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}