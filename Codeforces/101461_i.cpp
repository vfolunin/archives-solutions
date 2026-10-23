#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int index;
    if (!(cin >> index))
        return 0;

    cout << "TERM " << index;

    int row = 1;
    while (index > row) {
        index -= row;
        row++;
    }

    if (row % 2)
        index = row - index + 1;

    cout << " IS " << index << "/" << row - index + 1 << "\n";
    return 1;
}

int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);

    while (solve());
}