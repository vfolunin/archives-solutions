#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void eulerRec(vector<multiset<int>> &graph, int v, vector<int> &cycle) {
	while (!graph[v].empty()) {
		int to = *graph[v].begin();
		graph[v].erase(graph[v].find(to));
		eulerRec(graph, to, cycle);
	}
	cycle.push_back(v);
}

vector<int> euler(vector<multiset<int>> &graph) {
	vector<int> cycle;
	eulerRec(graph, 0, cycle);
	reverse(cycle.begin(), cycle.end());
	return cycle;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount;

	vector<multiset<int>> graph(vertexCount);
	for (int i = 0; i < edgeCount; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	vector<int> path = euler(graph);

	cout << path.size() - 1 << "\n";
	for (int v : path)
		cout << v + 1 << " ";
}