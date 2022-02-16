#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int num, int den) {
    if (num == den)
        return 1;
    if (num < den)
        return rec(num, den - num) * 2;
    else
        return rec(num - den, den) * 2 + 1;
}

void solve() {
    int test, num, den;
    char slash;
    cin >> test >> num >> slash >> den;

    cout << test << " " << rec(num, den) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}