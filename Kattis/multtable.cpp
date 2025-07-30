#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long size, n;
    cin >> size >> n;

    long long res = 0;
    for (long long d = 1; d <= size && d * d <= n; d++) {
        if (n % d == 0) {
            long long d2 = n / d;
            if (d2 <= size) {
                res++;
                res += d != d2;
            }
        }
    }

    cout << res;
}