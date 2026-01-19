#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> res(size, vector<int>(size));
    for (int y = 0; y < res.size(); y++) {
        for (int x = 0; x <= y; x++) {
            cin >> res[y][x];
            if (y) {
                if (!x)
                    res[y][x] += res[y - 1][x];
                else if (x == y)
                    res[y][x] += res[y - 1][x - 1];
                else
                    res[y][x] += max(res[y - 1][x - 1], res[y - 1][x]);
            }
        }
    }

    cout << *max_element(res.back().begin(), res.back().end());
}