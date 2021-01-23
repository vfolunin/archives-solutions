#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int targetLength, barCount;
    cin >> targetLength >> barCount;

    vector<int> can(targetLength + 1);
    can[0] = 1;

    for (int i = 0; i < barCount; i++) {
        int barLength;
        cin >> barLength;
        for (int length = targetLength; length >= barLength; length--)
            can[length] |= can[length - barLength];
    }

    cout << (can[targetLength] ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}