#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int reviewCount, paperCount;
	cin >> reviewCount >> paperCount;

	if (!reviewCount && !paperCount)
		return 0;

	vector<string> name(paperCount);
	vector<unordered_set<int>> reviewers(paperCount);
	for (int i = 0; i < paperCount; i++) {
		cin >> name[i];
		for (int j = 0; j < reviewCount; j++) {
			int paper;
			cin >> paper;
			reviewers[paper - 1].insert(i);
		}
	}

	int problemCount = 0;
	for (int i = 0; i < paperCount; i++) {
		bool hasProblem = reviewers[i].size() != reviewCount;
		for (int reviewer : reviewers[i])
			hasProblem |= name[reviewer] == name[i];
		problemCount += hasProblem;
	}

	if (problemCount == 0)
		cout << "NO PROBLEMS FOUND\n";
	else if (problemCount == 1)
		cout << "1 PROBLEM FOUND\n";
	else
		cout << problemCount << " PROBLEMS FOUND\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}