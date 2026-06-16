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

    long long n;
    cin >> n;

    long long res = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            res += d * d != n;
        }
    }

    cout << res;
}