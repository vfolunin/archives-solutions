#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int itemCount;
    cin >> itemCount;

    map<string, int> typeCount;
    for (int i = 0; i < itemCount; i++) {
        string type;
        cin >> type >> type;
        typeCount[type]++;
    }

    long long res = 1;
    for (auto &[type, count] : typeCount)
        res *= (count + 1);

    cout << res - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}