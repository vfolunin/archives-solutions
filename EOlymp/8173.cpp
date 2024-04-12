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

    map<int, int> count;
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        maxCount = max(maxCount, ++count[value]);
    }

    for (auto &[value, count] : count) {
        if (count == maxCount) {
            cout << value << "\n";
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}