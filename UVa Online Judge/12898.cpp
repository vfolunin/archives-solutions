#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long long l, r;
    cin >> l >> r;

    long long resAnd = 0, resOr = 0;
    for (int byte = 0; byte < 63; byte++) {
        resAnd |= ((long long)(l == r && l % 2)) << byte;
        resOr |= ((long long)(l < r || l % 2)) << byte;
        l /= 2;
        r /= 2;
    }

    cout << "Case " << test << ": " << resOr << " " << resAnd << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}