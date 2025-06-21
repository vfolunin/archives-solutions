#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string letters, a, b;
    cin >> letters >> a >> b;

    if (a == b)
        cout << "=\n";
    else if (lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [&](char lhs, char rhs) {
        return letters.find(lhs) < letters.find(rhs);
    }))
        cout << "<\n";
    else
        cout << ">\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}