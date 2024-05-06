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

    long long a, b, n;
    cin >> a >> b >> n;

    if (a * 3 <= b || n < 3) {
        cout << a * n;
        return 0;
    }

    long long res = 1e18;
    for (int an = 0; an < n && an < 100; an++)
        if ((n - an) % 3 == 0)
            res = min(res, an * a + (n - an) / 3 * b);
    cout << res;
}