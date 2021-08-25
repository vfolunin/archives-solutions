#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int storeCount, concertCount;
    cin >> storeCount >> concertCount;

    vector<vector<int>> profit(storeCount, vector<int>(concertCount));
    for (vector<int> &row : profit)
        for (int &x : row)
            cin >> x;

    vector<vector<int>> cost(storeCount, vector<int>(storeCount));
    for (vector<int> &row : cost)
        for (int &x : row)
            cin >> x;

    vector<vector<pair<int, int>>> graph(storeCount * concertCount);
    for (int sa = 0; sa < storeCount; sa++) {
        for (int sb = 0; sb < storeCount; sb++) {
            for (int c = 0; c + 1 < concertCount; c++) {
                int a = sa * concertCount + c;
                int b = sb * concertCount + c + 1;
                int w = profit[sb][c + 1] - cost[sa][sb];
                graph[a].push_back({ b, w });
            }
        }
    }

    vector<int> dist(storeCount * concertCount, -1e9);

    for (int s = 0; s < storeCount; s++)
        dist[s * concertCount] = profit[s][0];

    for (int c = 0; c + 1 < concertCount; c++) {
        for (int s = 0; s < storeCount; s++) {
            int v = s * concertCount + c;
            for (auto &[to, w] : graph[v])
                dist[to] = max(dist[to], dist[v] + w);
        }
    }

    cout << *max_element(dist.begin(), dist.end()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}