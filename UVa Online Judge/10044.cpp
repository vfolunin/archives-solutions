#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> bfs(map<int, set<int>> &graph, int v) {
	map<int, int> dist;
	queue<int> q;

	dist[v] = 0;
	q.push(v);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int to : graph[v]) {
			if (!dist.count(to)) {
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}

	return dist;
}

int getId(map<string, int> &vertexId, const string &vertexName) {
	if (!vertexId.count(vertexName))
		vertexId[vertexName] = vertexId.size();
	return vertexId[vertexName];
}

void solve(int test) {
	int lineCount, queryCount;
	cin >> lineCount >> queryCount;
	cin.ignore();

	map<string, int> vertexId;
	map<int, set<int>> graph;

	for (int i = 0; i < lineCount; i++) {
		string line;
		getline(cin, line);

		vector<int> ids;
		string vertexName;
		for (int j = 0; j < line.size(); j++) {
			if ((line[j] != ',' || line[j - 1] != '.') && line[j] != ':') {
				vertexName += line[j];
			} else {
				int id = getId(vertexId, vertexName);
				for (int id2 : ids) {
					graph[id].insert(id2);
					graph[id2].insert(id);
				}
				ids.push_back(id);

				vertexName.clear();
				if (line[j] == ',')
					j++;
				else
					break;
			}
		}
	}

	map<int, int> dist = bfs(graph, getId(vertexId, "Erdos, P."));

	cout << "Scenario " << test << "\n";
	for (int i = 0; i < queryCount; i++) {
		string vertexName;
		getline(cin, vertexName);
		cout << vertexName << " ";

		int id = getId(vertexId, vertexName);
		if (dist.count(id))
			cout << dist[id] << "\n";
		else
			cout << "infinity\n";
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int test = 1; test <= n; test++)
		solve(test);
}