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

    unordered_map<int, int> count;
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        maxCount = max(maxCount, ++count[value]);
    }

    int res = -1;
    for (auto &[value, count] : count) {
        if (count == maxCount) {
            if (res == -1) {
                res = value;
            } else {
                cout << "0\n";
                return;
            }
        }
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