#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getId(map<string, int> &id, string &name) {
    if (!id.count(name))
        id[name] = id.size();
    return id[name];
}

struct Edge {
    int to, startHour, finishHour;
};

bool coversDay(int l, int r) {
    while (1) {
        if (6 < l && l < 18)
            return 1;
        if (l == r)
            break;
        l = (l + 1) % 24;
    }
    return 0;
}

bool coversNoon(int l, int r) {
    while (1) {
        if (l == 12)
            return 1;
        if (l == r)
            break;
        l = (l + 1) % 24;
    }
    return 0;
}

void solve(int test) {
    int edgeCount;
    cin >> edgeCount;

    map<string, int> id;
    map<int, vector<Edge>> graph;

    for (int i = 0; i < edgeCount; i++) {
        string aName, bName;
        int startHour, duration;
        cin >> aName >> bName >> startHour >> duration;

        startHour %= 24;
        int a = getId(id, aName), b = getId(id, bName), finishHour = (startHour + duration) % 24;

        if (duration <= 12 && !coversDay(startHour, finishHour))
            graph[a].push_back({ b, startHour, finishHour });
    }

    string startName, finishName;
    cin >> startName >> finishName;

    int start = getId(id, startName), finish = getId(id, finishName);

    vector<vector<int>> visited(id.size(), vector<int>(24));
    vector<vector<int>> dist(id.size(), vector<int>(24, 1e9));
    dist[start][18] = 0;

    while (1) {
        int cv = -1, ch = -1;
        for (int v = 0; v < id.size(); v++) {
            for (int h = 0; h < 24; h++) {
                if (!visited[v][h] && (cv == -1 || dist[cv][ch] > dist[v][h])) {
                    cv = v;
                    ch = h;
                }
            }
        }

        if (cv == -1)
            break;
        visited[cv][ch] = 1;

        for (auto &[tv, sh, th] : graph[cv])
            dist[tv][th] = min(dist[tv][th], dist[cv][ch] + coversNoon(ch, sh));
    }

    int res = *min_element(dist[finish].begin(), dist[finish].end());

    cout << "Test Case " << test << ".\n";
    if (res == 1e9)
        cout << "There is no route Vladimir can take.\n";
    else
        cout << "Vladimir needs " << res << " litre(s) of blood.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int test = 1; test <= n; test++)
        solve(test);
}