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

	int size;
	cin >> size;

	set<pair<char, char>> pairs;
	for (int i = 0; i < size; i++) {
		string s;
		cin >> s;

		for (int j = 0; j + 1 < s.size(); j++) {
			pair<char, char> p = { s[j], s[j + 1] };
			if (p.first > p.second)
				swap(p.first, p.second);
			pairs.insert(p);
		}
	}

	cout << pairs.size();
}