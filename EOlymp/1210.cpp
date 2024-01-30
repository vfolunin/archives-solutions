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

    long long n, x;
    cin >> n >> x;

    if (x == 1) {
        cout << n * (n + 1) / 2;
        return 0;
    }

    long long p = 1, res = 0;
    for (int i = 1; i <= n; i++) {
        p *= x;
        res += i * p;
    }

    cout << res;
}