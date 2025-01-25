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

	vector<pair<string, int>> pairs;
	string name;
	int age;
	while (cin >> name >> age)
		pairs.push_back({ name, age });

	sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
		if (a.second != b.second)
			return a.second > b.second;
		return a.first < b.first;
	});

	for (auto &[name, age] : pairs)
		cout << name << "\n";
}