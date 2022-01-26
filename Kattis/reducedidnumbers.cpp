#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int idCount;
    cin >> idCount;

    vector<int> ids(idCount);
    for (int &id : ids)
        cin >> id;

    for (int mod = idCount; 1; mod++) {
        vector<int> seen(mod);
        bool ok = 1;
        for (int i = 0; ok && i < idCount; i++) {
            ok &= !seen[ids[i] % mod];
            seen[ids[i] % mod] = 1;
        }
        if (ok) {
            cout << mod << "\n";
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}