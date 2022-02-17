#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string text;
    cin >> text;

    int side = 1;
    while (side * side < text.size())
        side++;

    for (int i = 0; i < side * side; i++) {
        int y = side - 1 - i % side, x = i / side;
        int j = y * side + x;
        if (j < text.size())
            cout << text[j];
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