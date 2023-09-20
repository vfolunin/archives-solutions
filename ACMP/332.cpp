#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int vertexCount;
	cin >> vertexCount;
	vertexCount++;

	vector<int> dist(vertexCount, 1e9);
	dist[0] = 0;

	for (int v = 0; v < vertexCount; v++) {
		for (int to = v + 1; to < vertexCount; to++) {
			int weight;
			cin >> weight;

			dist[to] = min(dist[to], dist[v] + weight);
		}
	}

	cout << dist.back();
}