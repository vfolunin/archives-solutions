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

	int wordCount;
	cin >> wordCount;

	vector<string> words(wordCount);
	for (string &word : words)
		cin >> word;

	string target;
	cin >> target;

	vector<int> match(words.size());
	vector<int> from(target.size(), -1);

	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words[i].size(); j++) {
			if (words[i][j] == target[j]) {
				match[i]++;
				from[j] = i;
			}
		}
	}

	if (count(from.begin(), from.end(), -1)) {
		cout << -1;
		return 0;
	}

	int index = max_element(match.begin(), match.end()) - match.begin();
	vector<vector<int>> res;
	for (int i = 0; i < target.size(); i++)
		if (words[index][i] != target[i])
			res.push_back({ index, from[i], i });
	
	cout << res.size() << "\n";
	for (vector<int> &row : res) {
		for (int value : row)
			cout << value + 1 << " ";
		cout << "\n";
	}
}