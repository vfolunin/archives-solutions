#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int reviewCount, paperCount;
	cin >> reviewCount >> paperCount;

	if (!reviewCount && !paperCount)
		return 0;

	vector<string> university(paperCount);
	vector<unordered_map<int, int>> reviewers(paperCount);
	for (int reviewer = 0; reviewer < paperCount; reviewer++) {
		cin >> university[reviewer];
		for (int i = 0; i < reviewCount; i++) {
			int paper;
			cin >> paper;
			paper--;
			reviewers[paper][reviewer]++;
		}
	}

	int problemCount = 0;
	for (int paper = 0; paper < paperCount; paper++) {
		bool hasProblem = reviewers[paper].size() != reviewCount;
		for (auto [reviewer, count] : reviewers[paper])
			hasProblem |= university[reviewer] == university[paper] || count > 1;
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