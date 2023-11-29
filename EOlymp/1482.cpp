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

    int ah, aw;
    cin >> ah >> aw;

    vector<vector<int>> a(ah, vector<int>(aw));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            cin >> a[y][x];

    int bh, bw;
    cin >> bh >> bw;

    if (aw != bh) {
        cout << -1;
        return 0;
    }

    vector<vector<int>> b(bh, vector<int>(bw));
    for (int y = 0; y < b.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            cin >> b[y][x];

    cout << ah << " " << bw << "\n";

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