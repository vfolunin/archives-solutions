#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(string s) {
	cout << s << endl;

	int ans;
	cin >> ans;
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string symbols;
	for (char c = 'A'; c <= 'Z'; c++)
		symbols += c;
	for (char c = 'a'; c <= 'z'; c++)
		symbols += c;
	for (char c = '0'; c <= '9'; c++)
		symbols += c;

	string s;
	while (1) {
		for (char c : symbols) {
			int ans = ask(s + c);
			if (ans == -1)
				return 0;
			if (ans == s.size() + 1) {
				s += c;
				break;
			}

			ans = ask(c + s);
			if (ans == -1)
				return 0;
			if (ans == s.size() + 1) {
				s = c + s;
				break;
			}
		}
	}
}