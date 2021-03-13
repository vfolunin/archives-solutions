#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    map<int, int> k;
    for (int i = 0; i < aSize; i++) {
        int x;
        cin >> x;
        k[x]++;
    }
    for (int i = 0; i < bSize; i++) {
        int x;
        cin >> x;
        k[x]--;
    }

    int res = 0;
    for (auto &[_, cnt] : k)
        res += abs(cnt);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}