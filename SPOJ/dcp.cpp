#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long oddTo(long long n) {
    return n > 0 ? n / 3 * 2 + n % 3 : 0;
}

void solve(int test) {
    long long l, r;
    cin >> l >> r;

    if (l > r)
        swap(l, r);
    l--;
    r--;

    long long odd = oddTo(r) - oddTo(l - 1);

    cout << "Case " << test << ":\n";
    cout << "Odd = " << odd << "\n";
    cout << "Even = " << r - l + 1 - odd << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}