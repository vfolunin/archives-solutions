#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &awardsNeed, int typesCount) {
	vector<int> fromA(awardsNeed.size());
	vector<int> fromB(awardsNeed.size());
	
	int sizeA = fromA[0] = awardsNeed[0];
	int sizeB = typesCount - awardsNeed[0];

	for (int i = 1; i < awardsNeed.size(); ++i) {
		if (i % 2) {
			fromA[i] = min(sizeA - fromA[i - 1], awardsNeed[i]);
			fromB[i] = awardsNeed[i] - fromA[i];
		} else {
			fromB[i] = min(sizeB - fromB[i - 1], awardsNeed[i]);
			fromA[i] = awardsNeed[i] - fromB[i];
		}
	}

	return !fromA.back();
}

bool solve() {
	int guardCount;
	cin >> guardCount;

	if (!guardCount)
		return 0;

	vector<int> awardsNeed(guardCount);
	for (int &a : awardsNeed)
		cin >> a;

	if (guardCount == 1) {
		cout << awardsNeed[0] << "\n";
		return 1;
	}

	int minPairSum = 0;
	for (int i = 0; i < guardCount; i++)
		minPairSum = max(minPairSum, awardsNeed[i] + awardsNeed[(i + 1) % guardCount]);

	if (guardCount % 2 == 0) {
		cout << minPairSum << "\n";
	} else {
		int l = minPairSum - 1, r = 1e9;
		while (l + 1 < r) {
			int m = l + (r - l) / 2;
			if (can(awardsNeed, m))
				r = m;
			else
				l = m;
		}
		cout << r << "\n";
	}
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}