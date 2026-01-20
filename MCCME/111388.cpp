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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<vector<int>> a(size, vector<int>(size, 1));
    for (int i = 0; i < queryCount; i++) {
        int startY, startX, size;
        cin >> startY >> startX >> size;

        for (int y = 0; y < size && startY + y < a.size(); y++)
            for (int x = 0; x < size && startX + x < a.size(); x++)
                a[startY + y][startX + x] = 0;
    }

    int res = 0;
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            res += a[y][x];

    cout << res;
}