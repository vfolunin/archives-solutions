#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int elemCount, queryCount;
    if (!(cin >> elemCount >> queryCount))
        return 0;

    map<int, vector<int>> pos;
    for (int i = 0; i < elemCount; i++) {
        int elem;
        cin >> elem;
        pos[elem].push_back(i);
    }

    for (int i = 0; i < queryCount; i++) {
        int ind, elem;
        cin >> ind >> elem;
        cout << (ind <= pos[elem].size() ? pos[elem][ind - 1] + 1 : 0) << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}