#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int edgeCount;
	cin >> edgeCount;

	if (!edgeCount)
		return 0;

	vector<vector<int>> distY(26, vector<int>(26, 1e9));
	vector<vector<int>> distM(26, vector<int>(26, 1e9));

	for (int v = 0; v < 26; v++) {
		distY[v][v] = 0;
		distM[v][v] = 0;
	}

	for (int i = 0; i < edgeCount; i++) {
		char type, direction, a, b;
		int w;
		cin >> type >> direction >> a >> b >> w;
		if (type == 'Y') {
			distY[a - 'A'][b - 'A'] = min(distY[a - 'A'][b - 'A'], w);
			if (direction == 'B')
				distY[b - 'A'][a - 'A'] = min(distY[b - 'A'][a - 'A'], w);
		} else {
			distM[a - 'A'][b - 'A'] = min(distM[a - 'A'][b - 'A'], w);
			if (direction == 'B')
				distM[b - 'A'][a - 'A'] = min(distM[b - 'A'][a - 'A'], w);
		}
	}

	for (int v = 0; v < 26; v++) {
		for (int a = 0; a < 26; a++) {
			for (int b = 0; b < 26; b++) {
				distY[a][b] = min(distY[a][b], distY[a][v] + distY[v][b]);
				distM[a][b] = min(distM[a][b], distM[a][v] + distM[v][b]);
			}
		}
	}

	char a, b;
	cin >> a >> b;

	int minDist = 1e9;
	for (int v = 0; v < 26; v++)
		minDist = min(minDist, distY[a - 'A'][v] + distM[b - 'A'][v]);

	if (minDist == 1e9) {
		cout << "You will never meet.\n";
	} else {
		string meetingPoints;
		for (int v = 0; v < 26; v++)
			if (distY[a - 'A'][v] + distM[b - 'A'][v] == minDist)
				meetingPoints += 'A' + v;

		cout << minDist;
		for (char c : meetingPoints)
			cout << " " << c;
		cout << "\n";
	}
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}