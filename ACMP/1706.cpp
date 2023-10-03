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

	int schoolCount;
	cin >> schoolCount;

	map<string, vector<int>> scores;
	for (int i = 0; i < schoolCount; i++) {
		string user, school;
		int score;
		cin >> user >> score >> school;

		scores[school].push_back(score);
	}

	vector<pair<string, int>> schools;
	for (auto &[school, scores] : scores) {
		if (scores.size() >= 3) {
			sort(scores.rbegin(), scores.rend());
			schools.push_back({ school, scores[0] + scores[1] + scores[2] });
		}
	}

	sort(schools.begin(), schools.end(), [](auto &a, auto &b) {
		return a.second > b.second;
	});

	for (auto &[school, _] : schools)
		cout << school << "\n";
}