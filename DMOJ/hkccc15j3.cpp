#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queenCount;
    cin >> size >> queenCount;

    unordered_set<int> row, col, d1, d2;
    for (int i = 0; i < queenCount; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;

        row.insert(y);
        col.insert(x);
        d1.insert(y + x);
        d2.insert(y - x);
    }

    int res = 0;
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            res += !row.count(y) && !col.count(x) && !d1.count(y + x) && !d2.count(y - x);

    cout << res;
}