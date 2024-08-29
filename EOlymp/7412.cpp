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

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    vector<vector<int>> l(size, vector<int>(size));
    int lCount = 0;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (a[y][x] == '-')
                l[y][x] = 1 + (x ? l[y][x - 1] : 0);
            lCount += l[y][x] > 1 && (x == size - 1 || a[y][x + 1] != '-');
        }
    }

    vector<vector<int>> u(size, vector<int>(size));
    int uCount = 0;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (a[y][x] == '-')
                u[y][x] = 1 + (y ? u[y - 1][x] : 0);
            uCount += u[y][x] > 1 && (y == size - 1 || a[y + 1][x] != '-');
        }
    }

    cout << lCount << " " << uCount;
}