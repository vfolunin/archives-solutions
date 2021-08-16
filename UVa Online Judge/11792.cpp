#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

void solve() {
    int stationCount, lineCount;
    cin >> stationCount >> lineCount;

    vector<vector<pair<int, int>>> pos(stationCount);
    for (int line = 0; line < lineCount; line++) {
        for (int point = 0; 1; point++) {
            int station;
            cin >> station;

            if (!station)
                break;

            pos[station - 1].push_back({ line, point });
        }
    }

    vector<int> critical;
    vector<vector<pair<int, int>>> criticalOnLine(lineCount);
    for (int station = 0; station < stationCount; station++) {
        if (pos[station].size() > 1) {
            critical.push_back(station);
            for (auto &[line, point] : pos[station])
                criticalOnLine[line].push_back({ station, point });
        }
    }

    vector<vector<int>> dist(critical.size(), vector<int>(critical.size(), 1e9));

    for (int v = 0; v < critical.size(); v++)
        dist[v][v] = 0;

    for (int line = 0; line < lineCount; line++) {
        for (int i = 0; i < criticalOnLine[line].size(); i++) {
            auto &[sa, pa] = criticalOnLine[line][i];
            int a = lower_bound(critical.begin(), critical.end(), sa) - critical.begin();
            for (int j = i + 1; j < criticalOnLine[line].size(); j++) {
                auto &[sb, pb] = criticalOnLine[line][j];
                int b = lower_bound(critical.begin(), critical.end(), sb) - critical.begin();
                dist[a][b] = dist[b][a] = min(dist[a][b], abs(pa - pb));
            }
        }
    }

    for (int v = 0; v < critical.size(); v++)
        for (int a = 0; a < critical.size(); a++)
            for (int b = 0; b < critical.size(); b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int best = 0, bestSum = accumulate(dist[0].begin(), dist[0].end(), 0);
    for (int v = 1; v < critical.size(); v++) {
        int sum = accumulate(dist[v].begin(), dist[v].end(), 0);;
        if (bestSum > sum) {
            bestSum = sum;
            best = v;
        }
    }

    cout << "Krochanska is in: " << critical[best] + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}