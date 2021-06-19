#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<int, int>> bfs(vector<vector<int>> &doors, vector<vector<int>> &switches) {
    vector<vector<pair<int, int>>> pred(1 << doors.size(), vector<pair<int, int>>(doors.size(), { -1, -1 }));
    queue<int> q;

    pred[1][0] = { -2, -2 };
    q.push(1);
    q.push(0);

    while (!q.empty()) {
        int mask = q.front();
        q.pop();
        int v = q.front();
        q.pop();

        for (int to : doors[v]) {
            if ((mask & (1 << to)) && pred[mask][to].first == -1) {
                pred[mask][to] = { mask, v };
                q.push(mask);
                q.push(to);
            }
        }

        for (int s : switches[v]) {
            if (s != v && pred[mask ^ (1 << s)][v].first == -1) {
                pred[mask ^ (1 << s)][v] = { mask, v };
                q.push(mask ^ (1 << s));
                q.push(v);
            }
        }
    }

    vector<pair<int, int>> path;
    if (pred[1 << (doors.size() - 1)][doors.size() - 1].first != -1) {
        for (int mask = 1 << (doors.size() - 1), v = doors.size() - 1; mask != -2; ) {
            path.push_back({ mask, v });
            auto [pMask, pV] = pred[mask][v];
            mask = pMask;
            v = pV;
        }
        reverse(path.begin(), path.end());
    }
    return path;
}

int onePos(int mask) {
    int res = 0;
    while (mask > 1) {
        res++;
        mask >>= 1;
    }
    return res;
}

bool solve(int test) {
    int roomCount, doorCount, switchCount;
    cin >> roomCount >> doorCount >> switchCount;

    if (!roomCount)
        return 0;

    vector<vector<int>> doors(roomCount);
    for (int i = 0; i < doorCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        doors[a].push_back(b);
        doors[b].push_back(a);
    }

    vector<vector<int>> switches(roomCount);
    for (int i = 0; i < switchCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        switches[a].push_back(b);
    }

    vector<pair<int, int>> path = bfs(doors, switches);

    cout << "Villa #" << test << "\n";
    if (path.empty()) {
        cout << "The problem cannot be solved.\n\n";
    } else {
        cout << "The problem can be solved in " << path.size() - 1 << " steps:\n";
        for (int i = 0; i + 1 < path.size(); i++) {
            if (path[i].second != path[i + 1].second)
                cout << "- Move to room " << path[i + 1].second + 1 << ".\n";
            else if (path[i].first < path[i + 1].first)
                cout << "- Switch on light in room " << onePos(path[i].first ^ path[i + 1].first) + 1 << ".\n";
            else
                cout << "- Switch off light in room " << onePos(path[i].first ^ path[i + 1].first) + 1 << ".\n";
        }
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}