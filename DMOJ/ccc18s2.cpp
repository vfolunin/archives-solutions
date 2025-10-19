#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> a) {
    vector<vector<int>> res(a.size(), vector<int>(a.size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            res[y][x] = a[x][a.size() - 1 - y];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    while (a[0][0] >= a[0][1] || a[0][0] >= a[1][0])
        a = rotate(a);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}