#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string ask(int value) {
	cout << value << endl;

	string ans;
	cin >> ans;
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int l = 1, r = 100;
	while (l <= r) {
		int m = l + (r - l) / 2;
		string ans = ask(m);
		if (ans == "CORRECT")
			break;
		else if (ans == "LESS")
			r = m - 1;
		else
			l = m + 1;
	}
}