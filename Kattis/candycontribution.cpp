#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish, long long startAmount) {
	vector<long long> dist(graph.size(), -1);
	set<pair<long long, int>> q;

	dist[start] = startAmount;
	q.insert({ dist[start], start });

	while (!q.empty()) {
		int v = prev(q.end())->second;
		q.erase(prev(q.end()));

		if (v == finish)
			return dist[finish];

		for (auto &[to, percentage] : graph[v]) {
			if (dist[to] < dist[v] * percentage / 100) {
				q.erase({ dist[to], to });
				dist[to] = dist[v] * percentage / 100;
				q.insert({ dist[to], to });
			}
		}
	}

	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int vertexCount, edgeCount, start, finish, startAmount;
	cin >> vertexCount >> edgeCount >> start >> finish >> startAmount;
	start--;
	finish--;

	vector<vector<pair<int, int>>> graph(vertexCount);
	for (int i = 0; i < edgeCount; i++) {
		int a, b, percentage;
		cin >> a >> b >> percentage;
		a--;
		b--;
		percentage = 100 - percentage;

		graph[a].push_back({ b, percentage });
		graph[b].push_back({ a, percentage });
	}

	cout << dijkstra(graph, start, finish, startAmount);
}