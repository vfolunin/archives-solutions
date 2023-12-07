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
	getline(cin, s);

	for (char &c : s)
		c = islower(c) ? toupper(c) : tolower(c);

	cout << s;
}