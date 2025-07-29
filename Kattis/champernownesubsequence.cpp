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

	string s;
	cin >> s >> s;

	int res = 0;
	for (int i = 0; i < s.size(); ) {
		res++;
		for (char c : to_string(res))
			i += i < s.size() && s[i] == c;
	}

	cout << res;
}