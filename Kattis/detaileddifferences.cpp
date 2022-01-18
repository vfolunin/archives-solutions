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

    cout << a << "\n";
    cout << b << "\n";
    for (int i = 0; i < a.size(); i++)
        cout << (a[i] == b[i] ? "." : "*");
    cout << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}