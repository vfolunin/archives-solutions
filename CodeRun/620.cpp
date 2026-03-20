#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getPrimeDivisorCount(long long n) {
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

    long long n;
    cin >> n;

    int res = 0;
    for (int count = 1; count < 30; count++)
        res += getPrimeDivisorCount(n - count) == count;

    cout << res;
}