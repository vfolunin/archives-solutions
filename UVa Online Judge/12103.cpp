#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> seen(26), cycleCount(27);
    for (int i = 0; i < 26; i++) {
        if (seen[i])
            continue;

        seen[i] = 1;
        int cycleLength = 1;

        for (int pos = s[i] - 'A'; pos != i; pos = s[pos] - 'A') {
            seen[pos] = 1;
            cycleLength++;
        }

        cycleCount[cycleLength]++;
    }

    for (int cycleLength = 2; cycleLength <= 26; cycleLength += 2) {
        if (cycleCount[cycleLength] % 2) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}