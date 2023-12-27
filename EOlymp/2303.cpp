#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    unordered_set<unsigned long long> prefixHashes, valueHashes;
    bool ok = 1;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        if (ok) {
            unsigned long long hash = 0;
            for (int i = 0; i < s.size(); i++) {
                hash = hash * 11 + s[i] - '0' + 1;
                if (i + 1 < s.size())
                    prefixHashes.insert(hash);
                if (valueHashes.count(hash) || i + 1 == s.size() && prefixHashes.count(hash))
                    ok = 0;
            }
            valueHashes.insert(hash);
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}