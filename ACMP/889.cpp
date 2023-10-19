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

	int resX, pairCount;
	cin >> resX >> pairCount;

	vector<pair<int, int>> pairs(pairCount);
	for (auto &[x, y] : pairs)
		cin >> x >> y;

	sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
		return a.second > b.second;
	});

	for (auto &[x, y] : pairs) {
		if (resX == x)
			resX++;
		else if (resX == x + 1)
			resX--;
	}

	cout << resX;
}