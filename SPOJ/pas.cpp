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

    for (int y = 1; y <= size; y++) {
        for (int x = size; x > 1; x--) {
            if (x <= y)
                cout << x;
            cout << "\t";
        }
        for (int x = 1; x <= y; x++)
            cout << x << (x < y ? "\t" : "\n");
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}