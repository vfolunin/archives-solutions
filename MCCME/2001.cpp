#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void bfs(string &start, string &finish) {
	unordered_map<string, int> dist;
	unordered_map<string, string> from;
	queue<string> q;

	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		string v = q.front();
		q.pop();

		if (v == finish) {
			vector<string> path;
			for ( ; !v.empty(); v = from[v])
				path.push_back(v);
			reverse(path.begin(), path.end());

			for (string &v : path)
				cout << v << "\n";
			return;
		}

		vector<string> neighbors;

		if (v.front() < '9') {
			v.front()++;
			neighbors.push_back(v);
			v.front()--;
		}
		
		if (v.back() > '1') {
			v.back()--;
			neighbors.push_back(v);
			v.back()++;
		}

		rotate(v.begin(), v.end() - 1, v.end());
		neighbors.push_back(v);
		rotate(v.begin(), v.begin() + 1, v.end());

		rotate(v.begin(), v.begin() + 1, v.end());
		neighbors.push_back(v);
		rotate(v.begin(), v.end() - 1, v.end());

		for (string &to : neighbors) {
			if (!dist.count(to)) {
				dist[to] = dist[v] + 1;
				from[to] = v;
				q.push(to);
			}
		}
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	string start, finish;
	cin >> start >> finish;

	bfs(start, finish);
}