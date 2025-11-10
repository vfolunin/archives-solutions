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

    vector<vector<int>> row(9, vector<int>(9));
    vector<vector<int>> col(9, vector<int>(9));
    vector<vector<int>> block(9, vector<int>(9));

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            int value;
            cin >> value;
            value--;

            int b = y / 3 * 3 + x / 3;
            if (row[y][value] || col[x][value] || block[b][value]) {
                cout << "INVALID!";
                return 0;
            }

            row[y][value] = col[x][value] = block[b][value] = 1;
        }
    }

    cout << "VALID";
}