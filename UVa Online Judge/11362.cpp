#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int phoneCount;
    cin >> phoneCount;

    vector<string> phones(phoneCount);
    for (string &phone : phones)
        cin >> phone;

    sort(phones.begin(), phones.end());
    for (int i = 1; i < phoneCount; i++) {
        if (phones[i].find(phones[i - 1]) == 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}