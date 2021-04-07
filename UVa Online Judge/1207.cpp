#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aSize, bSize;
    string a, b;
    if (!(cin >> aSize >> a >> bSize >> b))
        return 0;

    vector<vector<int>> dist(aSize + 1, vector<int>(bSize + 1));
    for (int i = 1; i <= aSize; i++)
        dist[i][0] = i;
    for (int i = 1; i <= bSize; i++)
        dist[0][i] = i;
    for (int i = 1; i <= aSize; i++) {
        for (int j = 1; j <= bSize; j++) {
            if (a[i - 1] == b[j - 1])
                dist[i][j] = dist[i - 1][j - 1];
            else
                dist[i][j] = 1 + min(min(dist[i - 1][j], dist[i][j - 1]), dist[i - 1][j - 1]);
        }
    }

    cout << dist[aSize][bSize] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}