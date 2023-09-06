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

    int h, hw, w;
    cin >> h >> hw >> w;

    vector<vector<int>> a(h, vector<int>(hw));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            cin >> a[y][x];

    vector<vector<int>> b(hw, vector<int>(w));
    for (int y = 0; y < b.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            cin >> b[y][x];

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < b[0].size(); x++) {
            int sum = 0;
            for (int i = 0; i < a[0].size(); i++)
                sum += a[y][i] * b[i][x];
            cout << sum << " ";
        }
        cout << "\n";
    }
}