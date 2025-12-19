#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitalRoot(int n) {
    if (n < 10)
        return n;

    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return digitalRoot(sum);
}

void solve() {
    string s;
    cin >> s;

    int sum = 0;
    for (char c : s)
        sum += c - '0';

    cout << digitalRoot(sum) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}