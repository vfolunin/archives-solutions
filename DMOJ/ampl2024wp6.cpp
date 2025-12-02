#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
	int res = 0;
	while (n) {
		res++;
		n &= n - 1;
	}
	return res;
}

pair<int, int> rec(vector<vector<int>> &dist, int mask) {
	static vector<pair<int, int>> memo(1 << 15, { -1, -1 });
	pair<int, int> &res = memo[mask];
	if (res.first != -1)
		return res;

	if (!mask)
		return res = { 0, 0 };

	int bi = ones(mask) - 1;

	res = { 1e9, -1e9 };
	for (int ai = 0; ai < dist.size(); ai++) {
		if (!(mask & (1 << ai)))
			continue;

		auto [minRec, maxRec] = rec(dist, mask ^ (1 << ai));
		res.first = min(res.first, minRec + dist[ai][bi]);
		res.second = max(res.second, maxRec + dist[ai][bi]);
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int pointCount;
	cin >> pointCount;

	vector<pair<int, int>> pointsA(pointCount);
	for (auto &[x, y] : pointsA)
		cin >> x >> y;

	vector<pair<int, int>> pointsB(pointCount);
	for (auto &[x, y] : pointsB)
		cin >> x >> y;

	vector<vector<int>> dist(pointCount, vector<int>(pointCount));
	for (int ai = 0; ai < pointCount; ai++) {
		for (int bi = 0; bi < pointCount; bi++) {
			int dx = pointsA[ai].first - pointsB[bi].first;
			int dy = pointsA[ai].second - pointsB[bi].second;
			dist[ai][bi] = dx * dx + dy * dy;
		}
	}

	auto [minRes, maxRes] = rec(dist, (1 << pointCount) - 1);

	cout << minRes << " " << maxRes;
}