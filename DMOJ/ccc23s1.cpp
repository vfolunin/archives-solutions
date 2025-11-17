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

    vector<vector<int>> a(2, vector<int>(size));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            cin >> a[y][x];

    int res = 0;
    for (int x = 0; x < a[0].size(); x++) {
        res += (a[0][x] + a[1][x]) * 3;
        res -= (x && a[0][x - 1] && a[0][x]) * 2;
        res -= (x && a[1][x - 1] && a[1][x]) * 2;
        res -= (x % 2 == 0 && a[0][x] && a[1][x]) * 2;
    }

    cout << res;
}