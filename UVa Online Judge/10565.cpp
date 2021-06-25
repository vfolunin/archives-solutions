#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    for (int x : a) {
        if (x) {
            cout << "1\n" << -x << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}