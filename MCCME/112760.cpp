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

    if (n == 0) {
        cout << 2;
        return 0;
    }
    if (n == 1) {
        cout << -1;
        return 0;
    }

    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            cout << d;
            return 0;
        }
    }

    cout << n;
}