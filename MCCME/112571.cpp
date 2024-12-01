#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time, x, y;

    bool canPreceed(Event &that, int speed) {
        return (that.time - time) * speed / 60.0 >= hypot(x - that.x, y - that.y);
    }

    friend istream &operator >> (istream &in, Event &e) {
        int h, m;
        char colon;
        in >> h >> colon >> m >> e.x >> e.y;
        e.time = h * 60 + m;
        return in;
    }
};

bool dfs(vector<vector<int>> &graphA, int vFromA, vector<int> &visited, vector<int> &pairFromA) {
    visited[vFromA] = 1;

    for (int vFromB : graphA[vFromA]) {
        int &toFromA = pairFromA[vFromB];

        if (toFromA == -1 || !visited[toFromA] && dfs(graphA, toFromA, visited, pairFromA)) {
            toFromA = vFromA;
            return 1;
        }
    }

    return 0;
}

int kuhn(vector<vector<int>> &graphA, int vertexCountB) {
    vector<int> pairFromA(vertexCountB, -1);

    for (int vFromA = 0; vFromA < graphA.size(); vFromA++) {
        vector<int> visited(graphA.size());
        dfs(graphA, vFromA, visited, pairFromA);
    }

    return graphA.size() - count(pairFromA.begin(), pairFromA.end(), -1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int eventCount, speed;
    cin >> eventCount >> speed;

    vector<Event> events(eventCount);
    for (Event &event : events)
        cin >> event;

    vector<vector<int>> graph(events.size());
    for (int a = 0; a < graph.size(); a++)
        for (int b = 0; b < graph.size(); b++)
            if (a != b && events[a].canPreceed(events[b], speed))
                graph[a].push_back(b);

    cout << graph.size() - kuhn(graph, graph.size());
}