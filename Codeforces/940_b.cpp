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

    long long n, d, a, b;
    cin >> n >> d >> a >> b;

    if (d == 1) {
        cout << (n - 1) * a;
        return 0;
    }

    long long res = 0;
    while (n >= d) {
        res += n % d * a;
        n -= n % d;
        res += min((n - n / d) * a, b);
        n /= d;
    }
    res += (n - 1) * a;

    cout << res;
}