#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    map<int, int> k;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        k[x]++;
    }

    cout << "Case " << test << ": ";
    for (auto &[_, cnt] : k) {
        if (cnt > n) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}