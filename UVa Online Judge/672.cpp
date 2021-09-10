#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Gangster {
    int time, prosperity, stoutness;

    bool operator < (const Gangster &that) const {
        return time < that.time;
    }
};

void solve(int test) {
    int gangsterCount, maxOpenness, maxTime;
    cin >> gangsterCount >> maxOpenness >> maxTime;

    vector<Gangster> gangsters(gangsterCount);

    for (auto &[time, prosperity, stoutness] : gangsters)
        cin >> time;
    for (auto &[time, prosperity, stoutness] : gangsters)
        cin >> prosperity;
    for (auto &[time, prosperity, stoutness] : gangsters)
        cin >> stoutness;

    sort(gangsters.begin(), gangsters.end());

    vector<vector<int>> bonus(maxTime + 1, vector<int>(maxOpenness + 1, -1));
    bonus[0][0] = 0;

    for (int t = 0, g = 0; t <= maxTime; t++) {
        for (int o = 0; o <= maxOpenness; o++) {
            if (t && o)
                bonus[t][o] = max(bonus[t][o], bonus[t - 1][o - 1]);
            if (t)
                bonus[t][o] = max(bonus[t][o], bonus[t - 1][o]);
            if (t && o < maxOpenness)
                bonus[t][o] = max(bonus[t][o], bonus[t - 1][o + 1]);

            if (bonus[t][o] != -1)
                for (int gi = g; gi < gangsterCount && t == gangsters[gi].time; gi++)
                    if (o == gangsters[gi].stoutness)
                        bonus[t][o] += gangsters[gi].prosperity;
        }
        while (g < gangsterCount && t == gangsters[g].time)
            g++;
    }

    if (test)
        cout << "\n";
    cout << *max_element(bonus.back().begin(), bonus.back().end()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}