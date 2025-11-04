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

	vector<vector<int>> graph(7);
    vector<int> inDegree(graph.size());

    for (auto &[a, b] : vector<pair<int, int>>{ { 1, 7 }, { 1, 4 }, { 2, 1 }, { 3, 4 }, { 3, 5 } }) {
        a--;
        b--;

        graph[a].push_back(b);
        inDegree[b]++;
    }

	while (1) {
		int a, b;
		cin >> a >> b;

		if (!a && !b)
			break;

        a--;
        b--;

		graph[a].push_back(b);
        inDegree[b]++;
	}

    set<int> q;
    for (int v = 0; v < graph.size(); v++)
        if (!inDegree[v])
            q.insert(v);

    vector<int> order(graph.size());
    for (int &v : order) {
        if (q.empty()) {
            cout << "Cannot complete these tasks. Going to bed.";
            return 0;
        }

        v = *q.begin();
        q.erase(q.begin());

        for (int from : graph[v])
            if (!--inDegree[from])
                q.insert(from);
    }

    for (int v : order)
        cout << v + 1 << " ";
}