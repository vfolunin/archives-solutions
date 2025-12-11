#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &a) {
    vector<vector<int>> res(a[0].size(), vector<int>(a.size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            res[x][a.size() - 1 - y] = a[y][x];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, count;
    cin >> h >> w >> count;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            cin >> a[y][x];

    count %= 4;
    for (int i = 0; i < count; i++)
        a = rotate(a);

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}