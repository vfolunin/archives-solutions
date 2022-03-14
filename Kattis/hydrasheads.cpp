#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs() {
    vector<vector<int>> dist(200, vector<int>(200, 1e9));
    queue<int> q;

    dist[0][0] = 0;
    q.push(0);
    q.push(0);

    while (!q.empty()) {
        int heads = q.front();
        q.pop();
        int tails = q.front();
        q.pop();

        static int dHeads[] = { 0, -1, 2 };
        static int dTails[] = { -1, 2, 0 };

        for (int d = 0; d < 3; d++) {
            int tHeads = heads + dHeads[d];
            int tTails = tails + dTails[d];
            if (0 <= tHeads && tHeads < 200 && 0 <= tTails && tTails < 200 && dist[tHeads][tTails] == 1e9) {
                dist[tHeads][tTails] = dist[heads][tails] + 1;
                q.push(tHeads);
                q.push(tTails);
            }
        }
    }

    return dist;
}

bool solve() {
    int heads, tails;
    cin >> heads >> tails;

    if (!heads && !tails)
        return 0;

    static vector<vector<int>> dist = bfs();

    cout << (dist[heads][tails] != 1e9 ? dist[heads][tails] : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}