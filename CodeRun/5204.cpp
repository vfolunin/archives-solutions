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

    int h, wh, w;
    cin >> h >> wh >> w;

    vector<vector<int>> a(h, vector<int>(wh));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            cin >> a[y][x];

    vector<vector<int>> b(wh, vector<int>(w));
    for (int y = 0; y < b.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            cin >> b[y][x];

    vector<vector<int>> res(a.size(), vector<int>(b[0].size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] += a[y][i] * b[i][x];

    for (int x = 0; x < res[0].size(); x++) {
        for (int y = 0; y < res.size(); y++)
            cout << res[y][x] << " ";
        cout << "\n";
    }
}