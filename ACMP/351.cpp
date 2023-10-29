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

	int size, maxJump;
	string s;
	cin >> size >> maxJump >> s;

	vector<int> res(s.size(), 1e9), last(26, -1e9);
	res[0] = 0;
	last[s[0] - 'A'] = 0;

	for (int i = 1; i < s.size(); i++) {
		for (int c = 0; c < last.size(); c++)
			if (last[c] + maxJump >= i)
				res[i] = min(res[i], res[last[c]] + (c != s[i] - 'A'));
		last[s[i] - 'A'] = i;
	}

	cout << res.back();
}