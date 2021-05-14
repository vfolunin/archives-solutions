#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(long long n) {
    return n ? digitSum(n / 10) + n % 10 : 0;
}

long long digitSumTo(long long n) {
    if (n <= 0)
        return 0;

    long long res = 0;

    while (1) {
        res += digitSum(n);
        if (n % 10)
            n--;
        else
            break;
    }
    n /= 10;

    return res + n * 45 + 10 * digitSumTo(n - 1);
}

bool solve() {
    int l, r;
    cin >> l >> r;

    if (!l && !r)
        return 0;

    if (l > r)
        swap(l, r);

    cout << digitSumTo(r) - digitSumTo(l - 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}