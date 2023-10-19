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

	int size, diffLimit;
	string s;
	cin >> size >> diffLimit >> s;

	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int l = i, r = i, diff = 0; 0 <= l && r < s.size(); l--, r++) {
			diff += s[l] != s[r];
			if (diff > diffLimit)
				break;
			res++;
		}
		for (int l = i, r = i + 1, diff = 0; 0 <= l && r < s.size(); l--, r++) {
			diff += s[l] != s[r];
			if (diff > diffLimit)
				break;
			res++;
		}
	}

	cout << res;
}