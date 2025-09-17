#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int index;
    cin >> index;

    for (int r = 1; 1; r++) {
        if (index > r) {
            index -= r;
        } else {
            cout << index - 1 << " " << r << "\n";
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