#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    int lcpSize = 0;
    while (lcpSize < a.size() && lcpSize < b.size() && a[lcpSize] == b[lcpSize])
        lcpSize++;

    cout << a.size() + b.size() - max(lcpSize - 1, 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}