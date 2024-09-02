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

    int n;
    cin >> n;

    int res = 0;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            n /= d;
            res += d;
        }
    }
    if (n > 1)
        res += n;

    cout << res;
}