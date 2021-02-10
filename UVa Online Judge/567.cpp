#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    vector<vector<int>> dist(20, vector<int>(20, 1e9));
    
    for (int a = 0; a < 19; a++) {
        int k;
        if (!(cin >> k))
            return 0;

        for (int i = 0; i < k; i++) {
            int b;
            cin >> b;
            b--;
            dist[a][b] = dist[b][a] = 1;
        }
    }

    for (int v = 0; v < 20; v++)
        for (int a = 0; a < 20; a++)
            for (int b = 0; b < 20; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int queryCount;
    cin >> queryCount;

    cout << "Test Set #" << test << "\n";
    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        cout << setw(2) << a << " to " << setw(2) << b << ": " << dist[a - 1][b - 1] << "\n";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}