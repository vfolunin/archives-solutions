#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int ka, kb, ta, tb, t;
    cin >> ka >> kb >> ta >> tb >> t;

    cout << (ka * ta + kb * tb + t + 13 <= 24 ? "Khushi\n" : "Hotash\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}