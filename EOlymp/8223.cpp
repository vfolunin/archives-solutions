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

    string s;
    int l, r;
    cin >> s >> l >> r;

    cout << r - l + 2 << "\n";
    for (int len = 1; l + len <= r; len++)
        cout << s.substr(l - 1, len) << "\n";
}