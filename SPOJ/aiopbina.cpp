#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, targetValue;
    cin >> size >> targetValue;

    int found = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        found |= value == targetValue;
    }

    cout << (found ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}