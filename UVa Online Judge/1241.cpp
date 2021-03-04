#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int roundCount, absentPlayerCount;
    cin >> roundCount >> absentPlayerCount;

    vector<int> absent(1 << roundCount);
    for (int i = 0; i < absentPlayerCount; i++) {
        int p;
        cin >> p;
        absent[p - 1] = 1;
    }

    int res = 0;
    while (absent.size() > 1) {
        vector<int> nextAbsent;
        for (int i = 0; i < absent.size(); i += 2) {
            res += absent[i] ^ absent[i + 1];
            nextAbsent.push_back(absent[i] & absent[i + 1]);
        }
        absent.swap(nextAbsent);
    }

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