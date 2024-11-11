#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount;

	vector<int> price(vertexCount);
	for (int &p : price)
		cin >> p;

	vector<vector<pair<int, int>>> graphA(vertexCount), graphB(vertexCount);
	for (int i = 0; i < edgeCount; i++) {
		int a, b, weightA, weightB;
		cin >> a >> b >> weightA >> weightB;
		a--;
		b--;

		graphA[a].push_back({ b, weightA });
		graphA[b].push_back({ a, weightA });
		graphB[a].push_back({ b, weightB });
		graphB[b].push_back({ a, weightB });
	}

	vector<int> distA = dijkstra(graphA, 0);
	vector<int> distB = dijkstra(graphB, vertexCount - 1);

	int res = 1e9;
	for (int v = 0; v < vertexCount; v++)
		res = min(res, distA[v] + distB[v] + price[v]);

	cout << res;
}