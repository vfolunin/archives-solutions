#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int primeDivisorCount(int n) {
    int res = 0;

    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            while (n % d == 0)
                n /= d;
        }
    }
    res += n != 1;

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int bestValue = 0, bestDivisorCount = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        int divisorCount = primeDivisorCount(value);
        if (bestDivisorCount < divisorCount || bestDivisorCount == divisorCount && bestValue > value) {
            bestDivisorCount = divisorCount;
            bestValue = value;
        }
    }

    cout << bestValue;
}