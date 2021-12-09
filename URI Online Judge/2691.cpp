#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    char x;
    cin >> a >> x >> b;

    for (int i = 5; i <= 10; i++) {
        cout << a << " x " << i << " = " << a * i;
        if (a != b)
            cout << " && " << b << " x " << i << " = " << b * i;
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}