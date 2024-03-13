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

	string a, b;
	cin >> a >> b;

	vector<vector<int>> aPos(26);
	for (int i = 0; i < a.size(); i++)
		aPos[a[i] - 'a'].push_back(i);

	vector<vector<int>> bPos(26);
	for (int i = 0; i < b.size(); i++)
		bPos[b[i] - 'a'].push_back(i);

	string res;

	for (int ai = 0, bi = 0; ai < a.size() && bi < b.size();) {
		bool found = 0;

		for (int letter = 25; letter >= 0; letter--) {
			auto aIt = lower_bound(aPos[letter].begin(), aPos[letter].end(), ai);
			auto bIt = lower_bound(bPos[letter].begin(), bPos[letter].end(), bi);

			if (aIt != aPos[letter].end() && bIt != bPos[letter].end()) {
				res += letter + 'a';
				found = 1;
				ai = *aIt + 1;
				bi = *bIt + 1;
				break;
			}
		}

		if (!found)
			break;
	}

	cout << res;
}