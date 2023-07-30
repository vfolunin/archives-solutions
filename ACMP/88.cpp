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

    int side = size * size;
    vector<vector<int>> a(side, vector<int>(side));
    vector<vector<int>> row(side, vector<int>(side));
    vector<vector<int>> col(side, vector<int>(side));
    vector<vector<int>> block(side, vector<int>(side));

    for (int y = 0; y < side; y++) {
        for (int x = 0; x < side; x++) {
            cin >> a[y][x];
            a[y][x]--;

            int b = y / size * size + x / size;

            if (a[y][x] >= side || row[y][a[y][x]] || col[x][a[y][x]] || block[b][a[y][x]]) {
                cout << "Incorrect";
                return 0;
            }

            row[y][a[y][x]] = col[x][a[y][x]] = block[b][a[y][x]] = 1;
        }
    }

    cout << "Correct";
}