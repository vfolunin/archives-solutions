#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s >> s;

    int row = 0, maxRow = 0;
    for (char c : s) {
        if (c == '#')
            row++;
        else
            row = 0;
        maxRow = max(maxRow, row);
    }

    cout << (maxRow + 1) / 2 << "\n"; 
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}