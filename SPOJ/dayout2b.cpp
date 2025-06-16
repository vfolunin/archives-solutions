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

    for (int i = size > 1 ? (1 << (size - 1)) : 0; i < (1 << size); i++) {
        for (int bit = size - 1; bit >= 0; bit--)
            cout << (i >> bit) % 2;
        cout << "\n";
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