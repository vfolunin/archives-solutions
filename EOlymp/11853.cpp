#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    set<pair<string, int>> pairs;
    set<string> as;
    set<int> bs;

    for (int i = 0; i < size; i++) {
        string a;
        int b;
        cin >> a >> b;

        pairs.insert({ a, b });
        as.insert(a);
        bs.insert(b);
    }

    cout << (pairs.size() == as.size() && pairs.size() == bs.size() ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
        solve();
}