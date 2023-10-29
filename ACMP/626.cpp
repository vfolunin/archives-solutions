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

	int ruleCount;
	cin >> ruleCount;

	set<pair<char, char>> rules;
	for (int i = 0; i < ruleCount; i++) {
		string rule;
		cin >> rule;
		rules.insert({ rule[0], rule[1] });
	}

	string s;
	cin >> s;

	string res;
	for (char c : s) {
		if (!res.empty() && rules.count({ res.back(), c }))
			res.pop_back();
		else
			res.push_back(c);
	}

	cout << res;
}