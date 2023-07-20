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

	int remainder = 0;
	for (char c : s)
		remainder = (remainder * 10 + c - '0') % 11;

	cout << (remainder ? "NO" : "YES");
}