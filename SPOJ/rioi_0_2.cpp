#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    unordered_map<string, int> count;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        count[s]++;
    }

    int res = 0;
    for (auto &[s, count] : count)
        res += count == 1;

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