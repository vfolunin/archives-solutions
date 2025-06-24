#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b, c, mod, n;
    cin >> a >> b >> c >> mod >> n;

    for (int i = 0; i < n; i++)
        a = (a + b) * c % mod;

    cout << a << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}