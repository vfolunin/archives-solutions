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
	cin >> s;

	for (char &c : s)
		c = min<int>(c, '9' - c + '0');

	if (s[0] == '0')
		s[0] = '9';

	cout << s;
}