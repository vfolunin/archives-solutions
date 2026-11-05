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

    cout << "TERMINO " << index;

    int row = 1;
    while (index > row) {
        index -= row;
        row++;
    }

    if (row % 2)
        index = row - index + 1;

    cout << " ES " << index << "/" << row - index + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}