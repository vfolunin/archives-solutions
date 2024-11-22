#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(5);
    for (int &value : a)
        cin >> value;

    vector<int> b(5);
    for (int &value : b)
        cin >> value;

    for (int ai = 0; ai < a.size(); ai++) {
        for (int bi = 0; bi < a.size(); bi++) {
            if (ai != bi && a[ai] == b[bi]) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}