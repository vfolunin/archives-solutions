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

    string a, b;
    cin >> a >> b;

    int an = a.size(), bn = b.size();

    int prefix = 0;
    while (prefix < an && prefix < bn && a[prefix] == b[prefix])
        prefix++;

    int suffix = 0;
    while (suffix < an && suffix < bn && a[an - 1 - suffix] == b[bn - 1 - suffix])
        suffix++;

    int res = max(0, bn - an);
    res = max(res, bn - prefix - suffix);

    cout << res << "\n";
}