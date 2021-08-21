#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    const int INF = 1e9;
    vector<vector<vector<int>>> dist(s.size(), vector<vector<int>>(24, vector<int>(17, INF)));
    set<vector<int>> q;

    dist[0][6][0] = 0;
    q.insert({ dist[0][6][0], 0, 6, 0 });

    cout << "Case #" << test << ": ";

    while (!q.empty()) {
        int pos = q.begin()->at(1);
        int time = q.begin()->at(2);
        int up = q.begin()->at(3);
        q.erase(q.begin());

        if (pos == s.size() - 1) {
            cout << dist[pos][time][up] << "\n";
            return;
        }

        if (s[pos] == '*' && (time <= 6 || 18 <= time))
            continue;

        int tPos = pos;
        int tTime = (time + 8) % 24;
        int tUp = 0;
        int w = 8;
        if (dist[tPos][tTime][tUp] > dist[pos][time][up] + w) {
            q.erase({ dist[tPos][tTime][tUp], tPos, tTime, tUp });
            dist[tPos][tTime][tUp] = dist[pos][time][up] + w;
            q.insert({ dist[tPos][tTime][tUp], tPos, tTime, tUp });
        }

        tPos = pos + 1;
        tTime = (time + 1) % 24;
        tUp = up + 1;
        w = 1;
        if (up < 16 && dist[tPos][tTime][tUp] > dist[pos][time][up] + w) {
            q.erase({ dist[tPos][tTime][tUp], tPos, tTime, tUp });
            dist[tPos][tTime][tUp] = dist[pos][time][up] + w;
            q.insert({ dist[tPos][tTime][tUp], tPos, tTime, tUp });
        }
    }

    cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}