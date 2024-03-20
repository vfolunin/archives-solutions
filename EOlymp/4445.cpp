#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int y, vector<int> &col, vector<int> &d1, vector<int> &d2) {
    if (y == col.size())
        return 1;

    int res = 0;

    for (int x = 0; x < col.size(); x++) {
        if (col[x] || d1[y + x] || d2[y - x + col.size()])
            continue;

        col[x] = d1[y + x] = d2[y - x + col.size()] = 1;
        res += rec(y + 1, col, d1, d2);
        col[x] = d1[y + x] = d2[y - x + col.size()] = 0;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> col(size), d1(size * 2), d2(size * 2);
    cout << rec(0, col, d1, d2);
}