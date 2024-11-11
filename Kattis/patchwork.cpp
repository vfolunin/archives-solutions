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

	int h, w, patchCount;
	cin >> h >> w >> patchCount;

	vector<vector<string>> patches(patchCount);
	for (vector<string> &patch : patches) {
		int h, w;
		cin >> h >> w;

		patch.resize(h);

		for (string &s : patch)
			cin >> s;
	}

	int opCount;
	cin >> opCount;

	vector<string> res(h, string(w, '.'));

	for (int i = 0; i < opCount; i++) {
		int fromY, fromX, patchIndex;
		cin >> fromY >> fromX >> patchIndex;
		patchIndex--;

		for (int y = 0; y < patches[patchIndex].size() && fromY + y < res.size(); y++)
			for (int x = 0; x < patches[patchIndex][0].size() && fromX + x < res[0].size(); x++)
				res[fromY + y][fromX + x] = patches[patchIndex][y][x];
	}

	for (string &s : res)
		cout << s << "\n";
}