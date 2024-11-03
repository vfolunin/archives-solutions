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

	int index;
	cin >> index;
	index--;

	for (int i = 1; 1; i++) {
		string s = to_string(i);
		if (index < s.size()) {
			cout << s[index];
			break;
		} else {
			index -= s.size();
		}
	}
}