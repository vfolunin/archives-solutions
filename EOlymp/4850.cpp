#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int bfs(int start, int finish) {
	vector<int> dist(1e5, 1e9);
	queue<int> q;

	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int to : { v * 3, v + digitSum(v), v - 2 }) {
			if (0 < to && to < dist.size() && dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}

	return dist[finish];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int start, finish;
	cin >> start >> finish;

	cout << bfs(start, finish);
}