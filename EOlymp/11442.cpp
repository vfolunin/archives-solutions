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

    map<int, int> ka;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ka[x]++;
    }

    map<int, int> kb;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        kb[x]++;
    }


    map<int, int> k;
    for (auto &[x, kb] : kb)
        if (ka[x] < kb)
            k[x] = kb - ka[x];
    
    int m;
    cin >> m;

    map<int, int> km;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        km[x]++;
    }

    for (auto &[x, k] : k) {
        if (km[x] < k) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}